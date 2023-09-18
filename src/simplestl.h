#ifndef NCNN_SIMPLESTL_H
#define NCNN_SIMPLESTL_H

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <cstring>

#if !NCNN_SIMPLESTL

#include <new>

#else

// allocation functions
NCNN_EXPORT void* operator new(size_t size);

#endif

namespace ncnn {

/**
 * Returns the maximum of two values.
 *
 * @param a The first value.
 * @param b The second value.
 * @return The maximum value between a and b.
 */
template <typename T>
const T& max(const T& a, const T& b)
{
    return (a < b ? b : a);
}

/**
 * Returns the minimum of two values.
 *
 * @tparam T The type of the values.
 * @param a The first value.
 * @param b The second value.
 * @return The minimum value.
 */
template <typename T>
const T& min(const T& a, const T& b)
{
    return (a < b ? a : b);
}

/**
 * Swaps the values of two variables.
 *
 * @tparam T the type of the variables
 * @param a reference to the first variable
 * @param b reference to the second variable
 *
 * @throws None
 */
template <typename T>
void swap(T& a, T& b)
{
    if (&a == &b) {
        return;  // 不进行交换
    }

    T temp = std::move(a);
    a = std::move(b);
    b = std::move(temp);
}

template <typename T1, typename T2>
struct pair {
    T1 first;  /**< The first element of the pair. */
    T2 second; /**< The second element of the pair. */

    /**
     * Default constructor.
     * Initializes both elements with their default values.
     */
    pair() : first(), second() {}

    /**
     * Constructor with values for both elements.
     * @param t1 The value for the first element.
     * @param t2 The value for the second element.
     */
    pair(const T1& t1, const T2& t2) : first{t1}, second{t2} {}
};

/**
 * Checks if two pairs are equal.
 *
 * @param x The first pair to compare.
 * @param y The second pair to compare.
 *
 * @return True if the pairs are equal, false otherwise.
 */
template <typename T1, typename T2>
bool operator==(const pair<T1, T2>& x, const pair<T1, T2>& y)
{
    // Check if the first elements are equal
    bool firstElementsEqual = (x.first == y.first);

    // Check if the second elements are equal
    bool secondElementsEqual = (x.second == y.second);

    // Return true if both elements are equal, false otherwise
    return (firstElementsEqual && secondElementsEqual);
}

template <typename T1, typename T2>
bool operator<(const pair<T1, T2>& x, const pair<T1, T2>& y)
{
    return (x.first < y.first ||
            (x.first == y.first && x.second < y.second));
}

template <typename T1, typename T2>
bool operator>(const pair<T1, T2>& x, const pair<T1, T2>& y)
{
    return (x.first > y.first ||
            (x.first == y.first && x.second > y.second));
}

template <typename T1, typename T2>
bool operator<=(const pair<T1, T2>& x, const pair<T1, T2>& y)
{
    return !(x > y);
}

template <typename T1, typename T2>
bool operator>=(const pair<T1, T2>& x, const pair<T1, T2>& y)
{
    return !(x < y);
}

template <typename T1, typename T2>
pair<T1, T2> make_pair(const T1& t1, const T2& t2)
{
    return pair<T1, T2>(t1, t2);
}

template <typename T>
struct node {
    node* prev_;
    node* next_;
    T     data_;

    node() : prev_(nullptr), next_(nullptr), data_() {}

    explicit node(const T& t) : prev_(nullptr), next_(nullptr), data_(t) {}
};

template <typename T>
struct iter_list {
    node<T>* curr_;

    // constructor
    iter_list() : curr_(nullptr) {}

    // copy constructor
    explicit iter_list(node<T>* n) : curr_(n) {}

    // copy assignment operator
    iter_list& operator=(const iter_list& i)
    {
        if (this == &i) {
            return *this;
        }
        curr_ = i.curr_;
        return *this;
    }

    // destructor
    ~iter_list() = default;

    // operator*
    T& operator*()
    {
        return curr_->data_;
    }

    // operator->
    T* operator->()
    {
        return &(curr_->data_);
    }

    // operator==
    bool operator==(const iter_list& i)
    {
        return curr_ == i.curr_;
    }

    // operator++
    iter_list& operator++()
    {
        curr_ = curr_->next_;
        return *this;
    }
};

}  // namespace ncnn

#endif  // NCNN_SIMPLESTL_H
/*
    MANGO Multimedia Development Platform
    Copyright (C) 2012-2017 Twilight Finland 3D Oy Ltd. All rights reserved.
*/
#pragma once

#include "vector.hpp"

namespace mango
{

    template <>
    struct Vector<int8, 32> : VectorBase<int8, 32>
    {
        using VectorType = simd::int8x32;

        simd::int8x32 m;

        explicit Vector() = default;

        Vector(int8 s)
        : m(simd::int8x32_set1(s))
        {
        }

        Vector(simd::int8x32 v)
        : m(v)
        {
        }

        Vector& operator = (simd::int8x32 v)
        {
            m = v;
            return *this;
        }

        Vector& operator = (int8 s)
        {
            m = simd::int8x32_set1(s);
            return *this;
        }

        operator simd::int8x32 () const
        {
            return m;
        }

        operator simd::int8x32 ()
        {
            return m;
        }
    };

    static inline const Vector<int8, 32> operator + (Vector<int8, 32> v)
    {
        return v;
    }

    static inline Vector<int8, 32> operator - (Vector<int8, 32> v)
    {
        return simd::sub(simd::int8x32_zero(), v);
    }

    static inline Vector<int8, 32>& operator += (Vector<int8, 32>& a, Vector<int8, 32> b)
    {
        a = simd::add(a, b);
        return a;
    }

    static inline Vector<int8, 32>& operator -= (Vector<int8, 32>& a, Vector<int8, 32> b)
    {
        a = simd::sub(a, b);
        return a;
    }

    static inline Vector<int8, 32> operator + (Vector<int8, 32> a, Vector<int8, 32> b)
    {
        return simd::add(a, b);
    }

    static inline Vector<int8, 32> operator - (Vector<int8, 32> a, Vector<int8, 32> b)
    {
        return simd::sub(a, b);
    }

    static inline Vector<int8, 32> nand(Vector<int8, 32> a, Vector<int8, 32> b)
    {
        return simd::bitwise_nand(a, b);
    }

    static inline Vector<int8, 32> operator & (Vector<int8, 32> a, Vector<int8, 32> b)
    {
        return simd::bitwise_and(a, b);
    }

    static inline Vector<int8, 32> operator | (Vector<int8, 32> a, Vector<int8, 32> b)
    {
        return simd::bitwise_or(a, b);
    }

    static inline Vector<int8, 32> operator ^ (Vector<int8, 32> a, Vector<int8, 32> b)
    {
        return simd::bitwise_xor(a, b);
    }

    static inline Vector<int8, 32> adds(Vector<int8, 32> a, Vector<int8, 32> b)
    {
        return simd::adds(a, b);
    }

    static inline Vector<int8, 32> subs(Vector<int8, 32> a, Vector<int8, 32> b)
    {
        return simd::subs(a, b);
    }

    static inline Vector<int8, 32> min(Vector<int8, 32> a, Vector<int8, 32> b)
    {
        return simd::min(a, b);
    }

    static inline Vector<int8, 32> max(Vector<int8, 32> a, Vector<int8, 32> b)
    {
        return simd::max(a, b);
    }

    static inline mask8x32 operator > (Vector<int8, 32> a, Vector<int8, 32> b)
    {
        return simd::compare_gt(a, b);
    }

    static inline mask8x32 operator < (Vector<int8, 32> a, Vector<int8, 32> b)
    {
        return simd::compare_gt(b, a);
    }

    static inline mask8x32 operator == (Vector<int8, 32> a, Vector<int8, 32> b)
    {
        return simd::compare_eq(a, b);
    }

    static inline Vector<int8, 32> select(mask8x32 mask, Vector<int8, 32> a, Vector<int8, 32> b)
    {
        return simd::select(mask, a, b);
    }

} // namespace mango

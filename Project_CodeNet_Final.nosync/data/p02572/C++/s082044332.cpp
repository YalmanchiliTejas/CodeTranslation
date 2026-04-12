# 1 "c.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "c.cpp"
# 1 "/home/tysm/dev/cpplib/bin/../include/cpplib/stdinc.hpp" 1
       
# 11 "/home/tysm/dev/cpplib/bin/../include/cpplib/stdinc.hpp"
# 1 "/home/tysm/dev/cpplib/bin/../stdlib/bits/stdc++.h" 1
 #include<bits/stdc++.h>
# 12 "/home/tysm/dev/cpplib/bin/../include/cpplib/stdinc.hpp" 2
# 1 "/home/tysm/dev/cpplib/bin/../stdlib/ext/pb_ds/assoc_container.hpp" 1
 #include<ext/pb_ds/assoc_container.hpp>
# 13 "/home/tysm/dev/cpplib/bin/../include/cpplib/stdinc.hpp" 2
# 1 "/home/tysm/dev/cpplib/bin/../stdlib/ext/pb_ds/tree_policy.hpp" 1
 #include<ext/pb_ds/tree_policy.hpp>
# 14 "/home/tysm/dev/cpplib/bin/../include/cpplib/stdinc.hpp" 2
# 23 "/home/tysm/dev/cpplib/bin/../include/cpplib/stdinc.hpp"
using namespace std;
using namespace __gnu_pbds;

using ii = pair<int64_t, int64_t>;
using tt = tuple<int64_t, int64_t, int64_t>;

using vi = vector<int64_t>;
using vd = vector<double>;
using vb = vector<bool>;
using vii = vector<ii>;
using vtt = vector<tt>;

using vvi = vector<vi>;
using vvd = vector<vd>;
using vvb = vector<vb>;
using vvii = vector<vii>;
using vvtt = vector<vtt>;
# 60 "/home/tysm/dev/cpplib/bin/../include/cpplib/stdinc.hpp"
template<typename T>
ostream &operator<<(ostream &lhs, const vector<T> &rhs)
{
    if(is_floating_point<T>::value)
        lhs << fixed << setprecision(10);
    for(size_t i = 0; i < rhs.size(); ++i) {
        if(i)
            lhs << ' ';
        lhs << rhs[i];
    }
    return lhs;
}

template<typename T, size_t N>
ostream &operator<<(ostream &lhs, const array<T, N> &rhs)
{
    if(is_floating_point<T>::value)
        lhs << fixed << setprecision(10);
    for(size_t i = 0; i < rhs.size(); ++i) {
        if(i)
            lhs << ' ';
        lhs << rhs[i];
    }
    return lhs;
}
# 2 "c.cpp" 2
# 1 "/home/tysm/dev/cpplib/bin/../include/cpplib/adt/modular.hpp" 1
       
# 1 "/home/tysm/dev/cpplib/bin/../include/cpplib/math/euclid.hpp" 1
       


/**
 * Euclidean GCD.
 *
 * Computes the greatest commom divisor of
 * two integers.
 *
 * Time Complexity: O(log(min(a, b))).
 * Space Complexity: O(1).
 */
uint64_t gcd(uint64_t a, uint64_t b)
{
    for(; a != 0; a %= b)
        swap(a, b);
    return b;
}

/**
 * Extended Euclidean GCD.
 *
 * Besides computing the GCD it also returns
 * the roots of a*x + b*y = gcd(a, b).
 *
 * Time Complexity: O(log(min(a, b))).
 * Space Complexity: O(1).
 */
tuple<uint64_t, int64_t, int64_t> extended_gcd(uint64_t a, uint64_t b)
{
    int64_t x = 0, y = 1, x1 = 1, y1 = 0;
    while(a != 0) {
        uint64_t q = b / a;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a, b) = make_tuple(b % a, a);
    }
    return make_tuple(b, x, y);
}

/**
 * Euclidean Derivated LCM.
 *
 * Time Complexity: O(log(min(a, b))).
 * Space Complexity: O(1).
 */
uint64_t lcm(const uint64_t a, const uint64_t b)
{
    // same as a*b/gcd(a, b) but avoiding overflow.
    return a / gcd(a, b) * b;
}
# 3 "/home/tysm/dev/cpplib/bin/../include/cpplib/adt/modular.hpp" 2


/**
 * Modular.
 *
 * Provides modular operations such as +, -,
 * *, /, multiplicative inverse and
 * binary exponentiation.
 *
 * Note: if __uint128_t is not present, *
 * may cause overflow before applying % if
 * the multiplication result >= pow(2, 64).
 *
 * Time Complexity: O(1).
 * Space Complexity: O(1).
 */
template<uint64_t M>
struct modular
{
    static_assert(M > 0, "M must be greater than 0.");

    uint64_t value;

    modular() :
        value(0) {}

    template<typename T>
    modular(const T value)
    {
        if(value >= 0)
            this->value = ((uint64_t)value < M ? value : (uint64_t)value % M);
        else {
            uint64_t abs_value = (-(uint64_t)value) % M;
            this->value = (abs_value == 0 ? 0 : M - abs_value);
        }
    }

    template<typename T>
    explicit operator T() const
    {
        return value;
    }

    modular operator-() const
    {
        return modular(value == 0 ? 0 : M - value);
    }

    modular &operator+=(const modular &rhs)
    {
        if(rhs.value >= M - value)
            value = rhs.value - (M - value);
        else
            value += rhs.value;
        return *this;
    }

    modular &operator-=(const modular &rhs)
    {
        if(rhs.value > value)
            value = M - (rhs.value - value);
        else
            value -= rhs.value;
        return *this;
    }

    modular &operator*=(const modular &rhs)
    {



        value = (uint64_t)value * rhs.value % M;

        return *this;
    }

    modular &operator/=(const modular &rhs)
    {
        return *this *= inverse(rhs);
    }

    /**
     * Modular Binary Exponentiation.
     *
     * Computes pow(b, e)%M.
     *
     * Time Complexity: O(log(e)).
     * Space Complexity: O(1).
     */
    friend modular exp(modular b, uint64_t e)
    {
        modular res = 1;
        for(; e > 0; e >>= 1) {
            if(e & 1)
                res *= b;
            b *= b;
        }
        return res;
    }

    /**
     * Modular Multiplicative Inverse.
     *
     * Computes the modular multiplicative
     * inverse of a with mod M.
     *
     * Time Complexity: O(log(a)).
     * Space Complexity: O(1).
     */
    friend modular inverse(const modular &a)
    {
        assert(a.value > 0);
        auto aux = extended_gcd(a.value, M);
        assert(get<0>(aux) == 1); // a and M must be coprimes.
        return modular(get<1>(aux));
    }

    friend modular operator+(modular lhs, const modular &rhs)
    {
        return lhs += rhs;
    }

    friend modular operator-(modular lhs, const modular &rhs)
    {
        return lhs -= rhs;
    }

    friend modular operator*(modular lhs, const modular &rhs)
    {
        return lhs *= rhs;
    }

    friend modular operator/(modular lhs, const modular &rhs)
    {
        return lhs /= rhs;
    }

    friend bool operator==(const modular &lhs, const modular &rhs)
    {
        return lhs.value == rhs.value;
    }

    friend bool operator!=(const modular &lhs, const modular &rhs)
    {
        return !(lhs == rhs);
    }

    friend string to_string(const modular &a)
    {
        return to_string(a.value);
    }

    friend ostream &operator<<(ostream &lhs, const modular &rhs)
    {
        return lhs << to_string(rhs);
    }
};

using mint = modular<((int64_t)1e9 + 7)>;
# 3 "c.cpp" 2

int32_t main(){
    (ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL));
    int64_t n;
    cin >> n;

    vi arr(n);
    for(int64_t &i:arr)
        cin >> i;

    mint sum = 0, ans = 0;
    for(int64_t i=0; i<n; ++i){
        ans += sum*arr[i];
        sum += arr[i];
    }
    cout << ans << "\n";
    return 0;
}

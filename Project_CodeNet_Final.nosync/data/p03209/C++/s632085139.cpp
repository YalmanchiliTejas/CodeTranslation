#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <cstdint>
#include <string.h>
#include <queue>

using namespace std;

const uint64_t cacheLenList[] = {
    1,
    5,
    13,
    29,
    61,
    125,
    253,
    509,
    1021,
    2045,
    4093,
    8189,
    16381,
    32765,
    65533,
    131069,
    262141,
    524285,
    1048573,
    2097149,
    4194301,
    8388605,
    16777213,
    33554429,
    67108861,
    134217725,
    268435453,
    536870909,
    1073741821,
    2147483645,
    4294967293,
    8589934589,
    17179869181,
    34359738365,
    68719476733,
    137438953469,
    274877906941,
    549755813885,
    1099511627773,
    2199023255549,
    4398046511101,
    8796093022205,
    17592186044413,
    35184372088829,
    70368744177661,
    140737488355325,
    281474976710653,
    562949953421309,
    1125899906842621,
    2251799813685245,
    4503599627370493,
};
const uint64_t cachePatiList[] = {
    1,
    3,
    7,
    15,
    31,
    63,
    127,
    255,
    511,
    1023,
    2047,
    4095,
    8191,
    16383,
    32767,
    65535,
    131071,
    262143,
    524287,
    1048575,
    2097151,
    4194303,
    8388607,
    16777215,
    33554431,
    67108863,
    134217727,
    268435455,
    536870911,
    1073741823,
    2147483647,
    4294967295,
    8589934591,
    17179869183,
    34359738367,
    68719476735,
    137438953471,
    274877906943,
    549755813887,
    1099511627775,
    2199023255551,
    4398046511103,
    8796093022207,
    17592186044415,
    35184372088831,
    70368744177663,
    140737488355327,
    281474976710655,
    562949953421311,
    1125899906842623,
    2251799813685247,
};
uint64_t calLen(uint64_t N)
{
    return cacheLenList[N];
    //return (N <= 0) ? 1
    //    : 3 + calLen(N-1) * 2;
}
uint64_t calPati(uint64_t N)
{
    return cachePatiList[N];
    //return (N <= 0) ? 1
    //    : 1 + calPati(N-1) * 2;
}

uint64_t func(uint64_t N, uint64_t X)
{
    if (X <= 0) {
        return 0;
    }

    auto len = calLen(N);
    auto halfLen = len / 2 + 1;
    //auto patiSum = calPati(N);

    uint64_t patiCount = 0;
    if (X < halfLen) {
        patiCount += func(N-1, X-1);
    } else if (X == halfLen) {
        patiCount = calPati(N - 1) + 1;
    } else if(len < X) {
        patiCount = calPati(N);
    } else {
        //前半分の分
        patiCount = calPati(N - 1) + 1;

        patiCount += func(N - 1, X - halfLen);
    }
    return patiCount;
}

int main()
{
    uint64_t N, X;
    cin >> N >> X;

    uint64_t patiCount = func(N, X);
    //cout << N << "," << X << endl;
    //cout << calLen(N) << ", " << calPati(N) << endl;
    cout << patiCount << endl;

    //cout << "const uint64_t cacheLenList[] = {" << endl;
    //for (int i = 0; i <= 50; ++i) {
    //    cout << calLen(i) << ", " << endl;
    //}
    //cout << "};" << endl;
    //cout << "const uint64_t cachePatiList[] = {" << endl;
    //for (int i = 0; i <= 50; ++i) {
    //    cout << calPati(i) << "," << endl;
    //}
    //cout << "};" << endl;
    return 0;
}
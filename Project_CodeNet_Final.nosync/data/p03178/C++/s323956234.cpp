#include <algorithm>
#include <cassert>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

const long long MM = 1e9 + 7;

int main() {

    string s;
    getline(cin, s); // input a string from stdin
    long long D;     // count all number whose sum of digits % D = 0
    cin >> D;

    long long N = s.size();         // N is string size
    vector<long long> K(N, 0);      // K stores N digits
    vector<long long> cummod(N, 0); // cummulative sum % D

    // digit index 0 ... N-1
    assert('9' - '0' == 9);
    assert('0' - '0' == 0);
    for (long long i = 0; i < N; i++) {
        K[i] = s[i] - '0'; // convert to number
    }

    long long TT = 0;
    for (long long i = 0; i < N; i++) {
        TT += K.at(i);
        TT %= D;
        cummod.at(i) = TT;
    }

    reverse(K.begin(), K.end());
    reverse(cummod.begin(), cummod.end());
    long long myans = (TT % D == 0);

    // F[i, j],  count all numbers with i digits (including 0) such that its sum
    // of digits % D =j
    vector<vector<long long>> F(D, vector<long long>(N, 0));
    for (long long i = 0; i < N; i++) {
        for (long long digit = 0; digit <= 9; digit++) {
            for (long long j = 0; j < D; j++) {
                long long target = (digit + j) % D;
                F.at(target).at(i) +=
                    ((i > 0) ? (F.at(j).at(i - 1)) : ((j == 0) ? 1 : 0)); //
                F.at(target).at(i) %= MM;
            }

            if (digit < K.at(i)) {
                long long res = D - ( (digit + ((i < N - 1) ? (cummod.at(i + 1)) : 0))% D);
                res = res % D;
                myans += (i > 0) ? (F.at(res).at(i - 1)) : ((res == 0) ? 1 : 0);
                myans %= MM;
            }
        }
    }
    cout << (myans - 1 + MM) % MM<< endl;

    return 0;
}
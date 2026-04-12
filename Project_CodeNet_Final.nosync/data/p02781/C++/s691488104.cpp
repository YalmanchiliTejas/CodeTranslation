#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <cctype>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <stdlib.h>
#include <tuple>
#include <iomanip>
#include <iterator>
#include <stdio.h>
#include <fstream>
#include <time.h>
#include <bit>
#include <bitset>
#include <cstdint>
using namespace std;
const double PI = 3.14159265358979323846;
const long long int MOD = 1000000000 + 7;
using ll = long long;

struct UnionFind {
    vector<int> parent;

    UnionFind(int N) : parent(N) {
        for (int i = 0; i < N; i++) {
            parent[i] = -1;
        }
    }

    int root(int i) {
        if (parent[i] < 0) {
            return i;
        }
        return (parent[i] = root(parent[i]));
    }

    bool unite(int from, int to) {
        int rx = root(from);
        int ry = root(to);
        if (rx != ry) {
            parent[ry] += parent[rx];
            parent[rx] = ry;

            return true;
        }
        else {
            return false;
        }
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }

    int treeSize(int x) {


        return -parent[root(x)];
    }
};

long long int modpow(long long int base, long long int pow, long long int mod) {
    if (pow == 1) {
        return base;
    }
    else if (pow == 0) {
        return 1;
    }

    if (pow % 2 == 0) {
        auto temp = modpow(base, pow / 2, mod);
        return (temp * temp) % mod;
    }
    else {
        return (base * modpow(base, pow - 1, mod)) % mod;
    }
}

long long int moddiv(long long int X, long long int Y, long long int mod) {
    auto fermatDiv = modpow(Y, mod - 2, mod);

    return (X * fermatDiv) % mod;
}

long long modCombination(long long left, long long right, long long int mod) {
    long long answer = 1;
    if (left > right) {
        for (long long i = 0; i < right; i++) {
            answer = (answer * (left - i)) % mod;
            answer = moddiv(answer, (i + 1), mod);
        }
    }
    return answer;
}

bool IsPrime(long long N) {
    if (N == 1) {
        return false;
    }
    for (long long i = 2; i * i <= N; i++) {
        if (N % i == 0) {
            return false;
        }
    }


    return true;
}


vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; // 指数

        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
            
        }

        // その結果を push
        res.push_back({ a, ex });
    }

    // 最後に残った数について
    if (N != 1) res.push_back({ N, 1 });
    return res;
}

vector<long long> enum_divisors(long long N) {
    vector<long long> res;
    for (long long i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            res.push_back(i);
            // 重複しないならば i の相方である N/i も push
            if (N / i != i) res.push_back(N / i);
        }
    }
    // 小さい順に並び替える
    sort(res.begin(), res.end());
    return res;
}

long long gcd(long long a, long long b) {
    if (b > a) {
        long long temp = b;
        b = a;
        a = temp;
    }
    //cout << "a:" << a << "b:" << b << endl;
    long long c = a % b;
    if (c == 0) {
        return b;
    }
    else {
        return gcd(b, c);
    }
}





int main() {
    string s;
    cin >> s;
    int K;
    cin >> K;
    ll N = s.size();

    if (K > N) {
        cout << 0 << endl;
        return 0;
    }

    if (K == 1) {
        ll answer = (N - 1) * 9;
        answer += s[0] - '0';

        cout << answer << endl;
    }
    else if (K == 2) {
        ll answer = ((N - 1) * (N - 2) * 9 * 9) / 2;
        answer += (s[0] - '0' - 1) * (9 * (N - 1));

        int secondDigit = 0;
        int nonzeroDigit = 0;
        for (int i = 0; i < N; i++) {
            if (s[i] != '0') {
                nonzeroDigit++;
            }
            if (nonzeroDigit == 2) {
                secondDigit = i;
                break;
            }
        }

        if (secondDigit > 0) {
            answer += (N - (secondDigit + 1)) * 9;
            answer += s[secondDigit] - '0';
        }

        cout << answer << endl;
    }
    else {
        ll answer = ((N - 1) * (N - 2) * (N - 3) * 9 * 9 * 9) / 6;
        answer += (s[0] - '0' - 1) * (N - 1) * 9 * (N - 2) * 9 / 2;

        int secondDigit = 0;
        int nonzeroDigit = 0;
        for (int i = 0; i < N; i++) {
            if (s[i] != '0') {
                nonzeroDigit++;
            }
            if (nonzeroDigit == 2) {
                secondDigit = i;
                break;
            }
        }

        if (secondDigit > 0) {
            answer += ((N - (secondDigit + 1)) * (N - (secondDigit + 2)) * 9 * 9) / 2;
            

            answer += (s[secondDigit] - '0' - 1) * (N - (secondDigit + 1)) * 9;

            int thirdDigit = 0;
            nonzeroDigit = 0;
            for (int i = 0; i < N; i++) {
                if (s[i] != '0') {
                    nonzeroDigit++;
                }
                if (nonzeroDigit == 3) {
                    thirdDigit = i;
                    break;
                }
            }

            if (thirdDigit > 0) {
                answer += s[thirdDigit] - '0';
                answer += (N - (thirdDigit + 1)) * 9;
            }
        }

        cout << answer << endl;
    }

    return 0;
}

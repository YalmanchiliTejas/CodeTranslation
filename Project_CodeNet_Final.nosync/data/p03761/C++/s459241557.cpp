#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <functional>
#include <map>
#include <set>
#include <stack>
#include <deque>

#define INF 1000000000;
#define MOD 1000000007;
#define LIMIT 1000000000000000000;
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
typedef pair<int, int> P;

template<typename T>
T gcd(T a, T b) {
    return b ? gcd(b, a % b) : a;
}

template<typename T>
T lcm(T a, T b) {
    return (a * b) / gcd(a, b);
}

int main()
{
    int N; cin >> N;
    vector<vector<int>> counts(26, vector<int>(N));
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        for (auto c : s) {
            counts[c - 'a'][i]++;
        }
    }

    string ans = "";
    for (int i = 0; i < 26; i++) {
        int count = -1;
        for (int j = 0; j < N; j++) {
            if (0 <= counts[i][j]) {
                if (count == -1) {
                    count = counts[i][j];
                }
                else {
                    count = min(count, counts[i][j]);
                }
            }
        }

        for (int k = 0; k < count; k++) {
            char x = i + 'a';
            ans += x;
        }
    }
    cout << ans << endl;
}
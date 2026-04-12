#include <bits/stdc++.h>

#define ld long double
#define ll long long int
#define ull unsigned long long int
#define vi vector<int>
#define vl vector<ll>
#define vvi vector< vector<int> >
#define vvl vector< vector<ll> >
#define repd(i, a, b) for (int i=(a);i<(b);i++)
#define rep(i, n) repd(i,0,n)
#define ALL(v) v.begin(), v.end()
#define INF 1e9

#define repd(i, a, b) for (int i=(a);i<(b);i++)
#define rep(i, n) repd(i,0,n)

using namespace std;

/**
 * calculate GCD(greatest common divisor)
 * @param a
 * @param b
 * @return
 */
unsigned euclidean_gcd(unsigned a, unsigned b) {
    if (a < b) return euclidean_gcd(b, a);
    unsigned r;
    while ((r = a % b)) {
        a = b;
        b = r;
    }
    return b;
}

/**
 * output answer
 * @tparam T
 * @param answer
 * @return
 */
template<typename T>
T output(T answer) {
    cout << answer << endl;
    return 0;
}

/** ----from here ---------------------------------------------------------- */

int main() {

    int N;
    cin >> N;
    int i;
    vector <string> a(N);
    rep(i, N) { cin >> a[i]; }
//    vector<int> f(26, 0);
    vector < vector<int> > f(N, vector<int>(26, 0));
    vector < vector<int> > b(N, vector<int>(26, 0));
    vector<int> c(26, 0);

    for (int i = 0; i < N; ++i) {
        string s = a[i];
        for (int j = 0; j < s.length(); ++j) {

            b[i][s[j] - 'a']++;
            if (f[i][s[j] - 'a'] == 0) {
                f[i][s[j] - 'a'] = 1;
            }
        }

    }

    for (int j = 0; j < 26; ++j) {
        int maxTemp = -1;
        for (int i = 0; i < N; ++i) {
            int temp = b[i][j];

            if (maxTemp == -1) {
                maxTemp = temp;
            }
            if (temp < maxTemp) {
                maxTemp = temp;
            }
        }
        if (maxTemp > 0) {
            c[j] = maxTemp;
        }
    }

    for (int i = 0; i < 26; ++i) {
        if (c[i] > 0) {
            for (int j = 0; j < c[i]; ++j) {
                char temp = i + 'a';
                cout << temp;
            }
        }
    }
    cout << endl;

}
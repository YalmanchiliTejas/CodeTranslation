#include <iostream>

#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include<cstdio>
#include<iomanip>

#define REP(i, n) for(int i=0;i<n;i++)
#define REP2(i, s, n) for(int i=s;i<n;i++)
#define REP_1(i, n) for(int i=1;i<n+1;i++)
#define bitSearch(bit, n) for(int bit = 0; bit < (1 << N); bit++)
using namespace std;

void printAns(int a) { cout << a << endl; }

void yesno(bool a) { if (a)cout << "Yes" << endl; else cout << "No" << endl; }

void YESNO(bool a) { if (a)cout << "YES" << endl; else cout << "NO" << endl; }

typedef long long ll;
typedef unsigned long ul;
typedef long double ld;

template<class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

ll INF = 10000000;
ll mod = 1000000007;//10^9+7


//番号ズレ注意！！
int main() {
    int N, H[110];
    cin >> N;
    int ans = 0;
    REP(i, N) {
        cin >> H[i];
        bool can = true;
        REP(j, i ) {
            if (H[j] > H[i]) {
                can = false;
                break;
            }
        }
        if (can)ans++;
    }
    printAns(ans);

}
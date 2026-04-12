#define TST 0
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <cctype>
#include <bits/stdc++.h>

using namespace std;
// for loop
#define F(i, L, R) for(long i = L; i < R; i++)
#define FE(i, L, R) for(long i = L; i <= R; i++)
// for (reversed)
#define FR(i, L, R) for(long i = L; i > R; i--)
#define FRE(i, L, R) for(long i = L; i >= R; i--)

// data types
#define Int long
#define ul unsigned long
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define us unsigned shoft

// vectors
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
#define ALL(c) (c).begin(),(c).end()
#define last(vec) vec.size()-1
#define lastEle(vec) vec[last(vec)]
#define pb push_back
#define InputV(a, n) F(i,0,n){long l; cin >> l; a.pb(l);}

// debug
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define printA(a, L, R) FE(i, L, R) cout << a[i] << (i==R?'\n':' ')
#define printAF(a, L) printA(a, 0, L-1)
#define printV(a) printA(a, 0, a.size()-1)
#define printM(a, n, m) F(i, 0, n){ FE(j, 0, m) cout << a[i][j] << (i==m?'\n':' ');}

// utils
#define char2int(c) (c-'0')
#define bit(x, i) (x&(1<<i))
#define space ' '
#define PI 3.14159265358979323

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

#define printMatrix(mat,n,m){ \
    F(i, 0, n){               \
        F(j, 0, m){           \
            cout << mat[i][j] << space;\
        }\
        cout << endl;\
    }\
}

int main() {
#if TST==1
    ifstream in ("input.txt");
    cin.rdbuf(in.rdbuf());
#endif
    int a,b,c;
    long x,y;
    cin >> a >> b >> c >> x >> y;
    ll ans = 100000000000;
    long limit;
    if(x > y)
        limit = x;
    else
        limit = y;
    long anum,bnum,cnum;
    for(long i = limit; i >= 0;i--){
        cnum = 2*i;
        anum = x-i>0? x-i:0;
        bnum = y-i>0? y-i:0;
        ll money = anum * a + bnum * b + cnum*c;
        ans = min(ans, money);
    }

#if TST==1
#endif
    cout << ans << endl;
}


#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <stack>
#include <istream>
#include <map>
#include <set>
#include <queue>
#define rep0(i,n) for (int i = 0; i < (n); ++i)  //0スタート
#define rep1(i,n) for (int i = 1; i < (n); ++i)  //1スタート
#define REP(i,a,b) for (int i = a; i < (b); ++i)  //aからbまで
#define print(x) cout<<x<<endl  //xを改行付きで出力
#define scan(x) cin>>x //xを入力
#define INF 1000000007  //最大値兼MOD
typedef long long ll;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
int main() {
cin.tie(0);
ios::sync_with_stdio(false);
/*
./a.exe
*/
int n;
cin>>n;
cout<<(n * 800) - (n / 15) * 200<<endl;
return 0;
}

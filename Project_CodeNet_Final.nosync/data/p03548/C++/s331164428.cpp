#include<bits/stdc++.h>
using namespace std;
#define ALL(obj) (obj).begin(), (obj).end()
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for(int i = (a); i >= (b); i--)
#define REP(i, n) for(int i = 0; i < (n); ++i)
#define RREP(i, n) for(int i = n; i >= n; i--)

#define ABS(a) ((a < 0) ? ((-1)*(a)) : (a))

#define endl "\n"
#define pb push_back
#define rtn return

#define INF 2000000000	//int型は2 * 10^9ぐらいまで
#define MOD 1000000007
 
const int dx[]={1,0,-1,0}, dy[]={0,-1,0,1};

typedef long long ll;
typedef unsigned long long ull;

template <typename T>
inline T GCD(T a,T b){T c;while(b!=0){c=a%b;a=b;b=c;}return a;}
template <typename T>
inline T LCM(T a,T b){T c=GCD(a,b);a/=c;return a*b;}
template <typename T>
inline T nCr(T a,T b){T i,r=1;for(i=1;i<=b;i++){r*=(a+1-i);r/=i;}return r;}
template <typename T>
inline T nHr(T a,T b){return nCr(a+b-1,b);}
template <typename T>
inline T POW(T a,T b){int i,r=1;for(i=1;i<=b;i++){r*=a;}return r;}

signed main(void){
	cin.tie(0);
   ios::sync_with_stdio(false);

   int x, y, z;
   cin >> x >> y >> z;
   cout << (x-z) / (y+z) << endl;
   
   rtn 0;
}
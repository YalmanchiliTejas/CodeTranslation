#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define MaxN 100010
//#define MOD 998244353
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define endl '\n'
#define LL long long
#define PII pair<int,int>
#define rint register int 
#define ULL unsigned long long
const int MOD=1e9+7;
//int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
//int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
template<class T> inline void read(T& x){
    x=0;int f=0;char ch=getchar();
    while( !isdigit(ch) ) f|=( ch == '-' ) , ch=getchar();
    while( isdigit(ch) )  x = ( x<<1 ) + ( x<<3 ) + ( ch^48 ) , ch=getchar();
    x = f ? -x : x;
}
template<class T> inline void print(T x){
	if ( x < 0 ) { putchar('-'); x = -x; }
	if ( x >= 10 ) print( x / 10 );
	putchar(x % 10 + '0');
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
    int x;
    cin>>x;
    if( x >= 30 ) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
	return 0; 
}

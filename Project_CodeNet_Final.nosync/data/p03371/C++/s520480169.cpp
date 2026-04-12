#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define MOD 1000000007
#define INF (1<<30)
#define LINF (1LL<<60)
#define endl "\n"
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define reprev(i,n) for(int (i)=(n-1);(i)>=0;(i)--)
#define Flag(x) (1<<(x))
#define Flagcount(x) __builtin_popcount(x)
#define pint pair<int,int>
#define pdouble pair<double,double>
typedef unsigned long long int ull;
typedef long long lint;
 
 int main(void){
     lint A,B,C,X,Y;
     cin >> A >> B >> C >> X >> Y;
     lint ans=200000*C,Cpi=100000;
     lint value=ans;
     rep(i,100000){
         value-=2*C;
         Cpi--;
         if(Cpi<X) value+=A;
         if(Cpi<Y) value+=B;
         ans=min(ans,value);
     }
     cout << ans << endl;
 }
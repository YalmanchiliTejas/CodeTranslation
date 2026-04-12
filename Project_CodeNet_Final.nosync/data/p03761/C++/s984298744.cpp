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
     int N;
     cin >> N;
     string S[N];
     rep(i,N) cin >> S[i];
     int L[N];
     rep(i,N) L[i]=S[i].length();
     int alf[N][26]={};
     rep(i,N) rep(j,L[i]) alf[i][S[i][j]-'a']++;
     rep(i,26){
         int count=INF;
         rep(j,N){
             int count2=alf[j][i];
             count=min(count,count2);
         }
         char ans='a'+i;
         if(count!=INF) rep(j,count) cout << ans;
     }
     cout << endl;
 } 
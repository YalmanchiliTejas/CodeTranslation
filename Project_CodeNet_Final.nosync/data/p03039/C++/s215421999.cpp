/*
   first we need to sort the all edges then updates them one after another .
   we update them according to the adjacent edges then maximize the answer of edge
*/
#include<queue>
#include<map>
#include <string>
#include<bits/stdc++.h>
#define pi 3.141592654
#define forr(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define input ios_base::sync_with_stdio(0);cin.tie(0);
//#define x real()
//#define y imag()
using namespace std;
typedef pair<double,double>pdd;
typedef long long  ll;
typedef pair<ll, ll>pii;
//typedef complex<double> point;
//template<typename T>T gcd(T x, T y) { if(y == 0)return x; else return gcd(y, x%y); }
//typedef bitset<30> mask;
//int x[8]={1,0,0,-1,-1,-1,1,1};
//int y[8]={0,1,-1,0,-1,1,-1,1};
//#define var(x) ((x)<<1)
//#define nvar(x) ((x)^1)

ll n,m,k,ans,mod=1e9+7;

ll f[200020];
ll fPower(ll b, ll p, ll m){    //O(log(p))
  ll res = 1;
  while(p){
    if(p&1) res = (res * b)%m;
    b = (b * b)%m;
    p >>= 1;
  }
  return res;
}

inline ll modInversePrime(ll a, ll p){     //O(log(p))
  return fPower(a, p-2, p);
}
ll nCr(int n,int r)
{
    return ((f[n]*modInversePrime(f[r],mod))%mod*modInversePrime(f[n-r],mod)+mod)%mod;
}
 main()
{

//cout<<Pow((ll)1000000,(ll)110);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//    char input[15];
//    scanf("%s", &input);  array of char
//  gets(c+1);  array of char
//printf("%s, ",name[k[i]].c_str());  printf of string
input;
cin>>n>>m>>k;
ll c=0;

forr(i,1,n-1)
{
    c+=i;
    ans+=(((m*m)%mod)*(c%mod))%mod;
    ans%=mod;
}
c=0;
forr(i,1,m-1)
{
    c+=i;
    ans+=(((n*n)%mod)*(c%mod))%mod;
    ans%=mod;
}


f[0]=1;
forr(i,1,200002)
f[i]=(f[i-1]*i)%mod;

ans*=nCr(n*m-2,k-2);
ans%=mod;

cout<<(ans+mod)%mod<<endl;


return 0;
}

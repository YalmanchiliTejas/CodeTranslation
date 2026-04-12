#include <algorithm>
#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <cmath>
#include <string>
#define ll long long
#define read(x) scanf("%d",&x);
#define readll(x) cin>>x;
#define FOR(x,a,b) for(int x=a;x<b;x++)
#define MP make_pair
#define PB push_back
#define pii pair<int,int>
#define readN(N,X) for(int i=0;i<N;i++) cin>>X[i];
#define pff pair<double,double>
using namespace std;

long long fastpow(int a, int b, int MOD)
{
    long long x=1,y=a; 
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=(x*y) % MOD;
        }
        y = (y*y) % MOD;
        b /= 2;
    }
    return x;
}

long long InverseEuler(int n, int MOD)
{
    return fastpow(n,MOD-2,MOD);
}
 
long long f[300000];
bool init;
long long C(int n, int r, int MOD)
{
    if (!init){
        init=1;
        f[0]=1;
        for (int i=1; i<300000;i++)
            f[i]= (f[i-1]*i) % MOD;
        
    }
    return (f[n]*((InverseEuler(f[r], MOD) * InverseEuler(f[n-r], MOD)) % MOD)) % MOD;
}
int N;
int a[220000];
int b[220000];

int main(){
  std::ios::sync_with_stdio(false);    
  cin>>N;
  readN(N,a);
  for (int i=0;i<N;i++){
    b[i] = a[i];
  }
  sort(a, a+N);

  for (int i=0;i<N;i++){
    if (b[i] < a[N/2]) cout<<a[N/2]<<endl;
    else cout<<a[N/2-1]<<endl;
  }
}

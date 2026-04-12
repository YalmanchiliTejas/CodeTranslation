#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include <bitset>
using namespace std;
#define INF 110000000000
#define MOD 1000000007
typedef long long ll;
typedef pair<ll,int> P;

ll a[100],p[100];

ll f(int N,ll X){
  if(X==0) return 0;
  else if(N==0) return 1;
  else if(X==1) return 0;
  else if(X<=1+a[N-1]) return f(N-1,X-1);
  else if(X==2+a[N-1]) return p[N-1]+1;
  else if(X<=2+2*a[N-1]) return p[N-1]+1+f(N-1,X-2-a[N-1]);
  else return 2*p[N-1]+1;
}

int main(){
  a[0]=1; p[0]=1;
  for(int i=1;i<=50;i++){
    a[i]=a[i-1]*2+3;
    p[i]=p[i-1]*2+1;
  }
  
  int N;
  ll X;

  cin>>N>>X;

  cout<<f(N,X)<<endl;
}

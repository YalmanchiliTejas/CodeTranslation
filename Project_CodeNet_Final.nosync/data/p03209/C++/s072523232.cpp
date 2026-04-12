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

ll p[100],a[100];

ll bur(int L,ll M){
  if(M==0) return 0;
  else if(L==0) return 1;
  else if(M<=1) return 0;
  else if(M<=1+a[L-1]) return bur(L-1,M-1);
  else if(M==2+a[L-1]) return p[L-1]+1;
  else if(M<=2*a[L-1]+2) return p[L-1]+1+bur(L-1,M-a[L-1]-2);
  else if(M==3+a[L-1]*2) return p[L];
}

int main(){
  int N;
  ll X;
  cin>>N>>X;

  p[0]=1; a[0]=1;

  for(int i=1;i<=N;i++){
    p[i]=2*p[i-1]+1;
    a[i]=2*a[i-1]+3;
  }

  cout<<bur(N,X)<<endl;
}

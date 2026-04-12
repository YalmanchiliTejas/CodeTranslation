#include<bits/stdc++.h>
using namespace std;
#define fr(i,n)  for(int i = 0;i<n;++i)
#define fri(i,a,b) for(int i= a;i<=b;++i)
#define fro(i,a,b) for(int i= a;i>=b;--i)
#define debug(P) cout<<#P<<" = "<<P<<endl;
#define fi first
#define se second
#define pb(x) push_back(x)
#define  mp(x,y) make_pair(x,y)
#define endl  "\n"
#define  ii  pair<int,int>
#define  LL  long long
#define  maxm(a,b,c)  max(a,max(b,c))
const int INF = 1e9+7;
const int MAXN = 3005;
LL dp[MAXN][MAXN];
int main(){
  int n;
  cin>>n;
  int a[n];
  for(int i = 0;i<n;++i){
  	cin>>a[i];
  }
  for(int L = n-1;L>=0;--L){
  	for(int R = L;R<n;++R){
  		if(L == R){
		  dp[L][R] = a[L];
		 
	}
  		else{
  			dp[L][R] = max(a[L] - dp[L+1][R] , a[R] - dp[L][R-1]);
		  }
	  }
  }
  cout<<dp[0][n-1];
  }
  

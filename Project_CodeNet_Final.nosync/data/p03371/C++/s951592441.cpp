#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define uli unsigned long long int
#define INF 99999999999
#define rep(i,m,n) for(lli i = m;i < n;i++)
#define rrep(i,m,n) for(lli i=m-1;i>=n;i--)
#define pb(n) push_back(n)
#define UE(N) N.erase(unique(N.begin(),N.end()),N.end());
#define Sort(n) sort(n.begin(), n.end())
#define Rev(n) reverse(n.begin(),n.end())
#define Out(S) cout << S << endl
#define NeOut(S) cout << S
#define HpOut(S) cout << setprecision(150) << S << endl
#define Vec(K,L,N,S) vector<L> K(N,S)
#define DV(K,L,N,M,R) vector<vector<L>> K(N, vector<L>(M,R))
#define pint pair<lli,lli>
#define Lower(v,X) lower_bound(v.begin(),v.end(),X)-v.begin();
#define mod 1000000007
#define MAX 5100000
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main(){
  lli A,B,C,D,E,L,R,X,Y,W,H,N,M,K,sum=0,num=0,flag=0;string S,T;
  cin >> A >> B >> C >> X >> Y;
  K=(A+B)/2;
  if(C<K){
    sum+=2*C*min(X,Y);
    num=min(X,Y);
  }
  sum+=A*(X-num)+B*(Y-num);
  num=2*C*max(X,Y);
  Out(min(sum,num));
}
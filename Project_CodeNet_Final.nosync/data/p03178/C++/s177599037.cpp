#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define uli unsigned long long int
#define INF 999999999999999999
#define rep(i,m,n) for(lli i = m;i < n;i++)
#define rrep(i,m,n) for(lli i=m-1;i>=n;i--)
#define pb(n) push_back(n)
#define UE(N) N.erase(unique(N.begin(),N.end()),N.end());
#define Sort(n) sort(n.begin(), n.end())
#define Rev(n) reverse(n.begin(),n.end())
#define Out(S) cout << S << endl
#define NeOut(S) cout << S
#define HpOut(S) cout << setprecision(30) << S << endl
#define Vec(K,L,N,S) vector<L> K(N,S)
#define DV(K,L,N,M,S) vector<vector<L>> K(N,vector<L>(M,S))
#define TV(K,L,N,M,R,S) vector<vector<vector<L>>> K(N,vector<vector<L>>(M,vector<L>(R,S)))
#define pint pair<lli,lli>
#define paf(L,R) pair<L,R>
#define mod 1000000007
#define MAX 5100000
#define ALL(a)  a.begin(),a.end()
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
int main(){
  lli A,B,C,D,E,F,N,M,K,L,R,X,Y,Z,H,W,sum=0,num=0,flag=0;string S,T;
  cin >> S >> D;
  N=S.size();
  TV(DP,lli,N,D,2,0);//桁DP:=上位i桁を決めたときの総和mod4がjになるものの総数
  rep(i,0,10)if(int(S[0]-'0')==i){DP[0][i%D][0]++;break;}else DP[0][i%D][1]++;
  rep(i,1,N)rep(j,0,D)rep(f,0,2)rep(k,0,10){
    int x=(j+k)%D;
    int y=S[i]-'0';
    if(!f&&y<k)continue;
    else if(!f&&y==k){
      DP[i][x][0]+=DP[i-1][j][0];
      DP[i][x][0]%=mod;
    }
    else{
      DP[i][x][1]+=DP[i-1][j][f];
      DP[i][x][1]%=mod;
    }
  }
  Out((DP[N-1][0][1]+DP[N-1][0][0]+mod-1)%mod);//0は入らない
}

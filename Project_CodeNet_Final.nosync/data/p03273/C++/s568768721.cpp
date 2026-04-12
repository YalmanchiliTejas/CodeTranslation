#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define uli unsigned long long int
#define INF 99999999999
#define rep(i,m,n) for(lli i = m;i < n;i++)
#define rrep(i,m,n) for(lli i=m;i>n;i--)
#define pb(n) push_back(n)
#define UE(N) N.erase(unique(N.begin(),N.end()),N.end());
#define Sort(n) sort(n.begin(), n.end())
#define Rev(n) reverse(n.begin(),n.end())
#define Out(S) cout << S << endl
#define NeOut(S) cout << S
#define HpOut(S) cout << setprecision(20) << S << endl
#define Vecpr(K,L1,L2,N) vector<pair<L1,L2>> K(N)
#define Vec(K,L,N,S) vector<L> K(N,S)
#define DV(K,L,N,M,R) vector<vector<L>> K(N, vector<L>(M,R))
#define mod 1000000007
#define MAX 5100000
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
int main(){
   lli A,B,C,N,M,K,L,R,sum=0,num=0;
   cin >> N >> M;
   K=N;
   Vec(P,string,0,"");Vec(Q,int,M,0);
   rep(i,0,N){
       string S;cin >> S;
       if(S.find('#')==string::npos)continue;
       else P.pb(S);
   }
   N=P.size();
   rep(i,0,N)rep(j,0,M)if(P[i][j]=='#')Q[j]++;
   rep(i,0,N){
       rep(j,0,M)if(Q[j])NeOut(P[i][j]);
       cout<<endl;
   }
}
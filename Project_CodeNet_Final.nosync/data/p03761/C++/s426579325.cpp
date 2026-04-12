#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,n) for(int i=(int)(j);i<(int)(n);i++)
#define REP(i,j,n) for(int i=(int)(j);i<=(int)(n);i++)
#define MOD 1000000007
#define int long long
#define ALL(a) (a).begin(),(a).end()
#define vi vector<int>
#define vii vector<vi>
#define pii pair<int,int>
#define priq priority_queue<int>
#define disup(A,key) distance(A.begin(),upper_bound(ALL(A),(int)(key)))
#define dislow(A,key) distance(A.begin(),lower_bound(ALL(A),(int)(key)))
signed main(){
  int N;
  cin>>N;
  vi A(26);
  string S;
  cin>>S;
  rep(i,0,S.size())
    A[S[i]-'a']++;
  rep(i,1,N){
    string X;
    cin>>X;
    vi B(26);
    rep(j,0,X.size())
      B[X[j]-'a']++;
    rep(j,0,26)
      A[j]=min(A[j],B[j]);
    } 
  string ans;
  rep(i,0,26){
    rep(k,0,A[i])
      ans+='a'+i;
    }
  cout<<ans;
  }

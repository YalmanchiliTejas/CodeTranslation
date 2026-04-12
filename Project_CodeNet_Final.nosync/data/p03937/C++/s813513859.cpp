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
#define tii tuple<int,int,int>
#define Priq priority_queue<int,vi,greater<int>>
#define pb push_back
#define mp make_pair
signed main(){
  int H,W; cin>>H>>W;
  vector<string> S(H);
  rep(i,0,H) cin>>S[i];
  queue<pii> Q;
  Q.push(mp(0,0));
  vi P={0,1},R={1,0};
  string ans="Impossible";
  int count=0;
  int sum=0;
  rep(i,0,H){
    rep(j,0,W){
      if(S[i][j]=='#')
        sum++;
    }
  }
  Q.push(mp(-1,-1));
  while(Q.size()>1){
    int X=Q.front().first,Y=Q.front().second;
    Q.pop();
    if(X==H-1&&Y==W-1&&count==sum-1){
      ans="Possible";
      break;
    }
    if(X==-1){
      count++;
      Q.push(mp(-1,-1));
    }
    else{
    rep(i,0,2){
      int A=X+P[i],B=Y+R[i];
      if(A<H&&B<W){
        if(S[A][B]=='#')
          Q.push(mp(A,B));
      }
    }
    }
  }
  cout<<ans<<endl;
  }

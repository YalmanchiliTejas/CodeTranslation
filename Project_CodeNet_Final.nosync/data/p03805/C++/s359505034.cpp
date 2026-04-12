#include<bits/stdc++.h>
using namespace std;
template <class A, class B> inline bool chmax(A &a, const B &b) { return b > a && (a = b, true); }
template <class A, class B> inline bool chmin(A &a, const B &b) { return b < a && (a = b, true); }
typedef long long ll;
typedef vector<int> vint;
typedef pair<int, int> pint;
typedef vector<long long> vlong;
#define _GLIBCXX_DEBUG
#define vpush(a,x) a.push_back(x);
#define rep(i, n) REP(i, 0, n)
#define all(v) v.begin(), v.end()
#define REP(i, x, n) for(int i = x; i < n; i++)
const int INF = 1 << 30;
const int dx[] = {1,0,-1,0,1,1,-1,-1};
const int dy[] = {0,-1,0,1,1,-1,-1,1};
#define stp(x)  setprecision(x)
int main(){
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  int n,m;
  cin>>n>>m;
  int a,b;
  vector<vector<int> > li(n+2);
  rep(i,m){
    cin>>a>>b;
    li[a].push_back(b);
    li[b].push_back(a);
  }
  vint pe;
  REP(i,1,n+1){
    pe.push_back(i);
  }
  bool flag;
  ll count=0;
  vector<vector<bool> > fg(10,vector<bool>(10));
  do{
    if(pe[0]!=1){
      break;
    }
    bool flag2=false;
    flag=true;
    rep(i,10){
      rep(j,10){
        fg[i][j]=false;
      }
    }
    int count2=0;
    for(int i=0;i<n-1;i++){
      int si=li[pe[i]].size();
      rep(j,si){
        if(li[pe[i]][j]==pe[i+1] && !fg[pe[i]][j]){
          flag2=true;
          /* fg[pe[i]][pe[i+1]]=true;
             fg[pe[i+1]][pe[i]]=true;*/
          count2++;
          break;
        }
      }
    }
    if(count2==n-1){
      count++;
    }
  }while(next_permutation(all(pe)));
  cout<<count<<'\n';
  return(0);
}  

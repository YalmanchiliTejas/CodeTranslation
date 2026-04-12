#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define fi first
#define se second
#define repl(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rep(i,n) repl(i,0,n)
#define each(itr,v) for(auto itr:v)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define dbg(x) cout<<#x"="<<x<<endl
#define mmax(x,y) (x>y?x:y)
#define mmin(x,y) (x<y?x:y)
#define maxch(x,y) x=mmax(x,y)
#define minch(x,y) x=mmin(x,y)
#define uni(x) x.erase(unique(all(x)),x.end())
#define exist(x,y) (find(all(x),y)!=x.end())
#define bcnt __builtin_popcount

#define INF INT_MAX/3

int n;
int h[22],w[22];
int cm[3];
int d[1<<16];
vector<int> mask;

int main(){
	cin.sync_with_stdio(false);
  cin>>n;
  rep(i,n)cin>>h[i]>>w[i];
  rep(i,4){
    string s;
    cin>>s;
    rep(j,4){
      if(s[j]=='R')cm[0]|=1<<(i*4+j);
      if(s[j]=='G')cm[1]|=1<<(i*4+j);
      if(s[j]=='B')cm[2]|=1<<(i*4+j);
    }
  }

  rep(k,n){
    repl(i,-h[k]+1,4)repl(j,-w[k]+1,4){
      int m=0;
      repl(ni,i,i+h[k])repl(nj,j,j+w[k]){
        if(ni>=0&&ni<4&&nj>=0&&nj<4)m|=1<<(ni*4+nj);
      }
      mask.pb(m);
    }
  }
  sort(all(mask)); uni(mask);

  rep(S,1<<16)d[S]=-1;
  
  d[0]=0;
  queue<int> que;
  que.push(0);
  while(que.size()){
    int S=que.front(); que.pop();
    if(S==(1<<16)-1){
      cout<<d[S]<<endl;
      break;
    }
    for(int msk : mask){
      rep(c,3){
        int cov=cm[c]&msk;
        int del=~(msk^cov);
        int nS=(S&del)|cov;
        if(d[nS]==-1){
          d[nS]=d[S]+1;
          que.push(nS);
        }
      }
    }
  }
  return 0; 
}
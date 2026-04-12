#include<iostream>
#include<map>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

#define fs first
#define sc second
typedef long long ll;
typedef pair<int,int> P;
typedef pair<P,ll> P2;

int n,h[16],w[16],ty,tx;
string s[4];
map<ll,bool> memo;
ll ans,tmp;
vector<ll> st;

inline int color(ll a,ll b){
  bool v[3];
  for(int k=0;k<3;k++)v[k] = false;
  for(int k=0;k<16;k++){
    if( ((a>>(2*k))&3LL) && ((b>>(2*k))&3LL)){
      v[((b>>(2*k))&3LL)-1] = true;
    }
  }
  int cnt = 0;
  for(int k=0;k<3;k++)if(v[k])cnt++;
  return cnt;
}

int main(){
  cin >> n;
  for(int i=0;i<n;i++)cin >> h[i] >> w[i];
  for(int i=0;i<4;i++)cin >> s[i];

  ans = 0;
  for(int i=0;i<4;i++)
    for(int j=0;j<4;j++){
      if(s[i][j] == 'R')ans += 1LL<<(2*(i*4+j));
      if(s[i][j] == 'G')ans += 2LL<<(2*(i*4+j));
      if(s[i][j] == 'B')ans += 3LL<<(2*(i*4+j));
    }

  for(int i=0;i<n;i++){
    for(int j=-h[i]+1;j<4;j++){
      for(int k=-w[i]+1;k<4;k++){
	tmp = 0;
	for(int y=0;y<h[i];y++){
	  for(int x=0;x<w[i];x++){
	    ty = y+j; tx = x+k;
	    if(ty<0 || tx<0 || 4<=ty || 4<=tx)continue;
	    tmp |= 1LL<<(2*(ty*4+tx));
	  }
	}
	st.push_back(tmp);
      }
    }
  }
  sort(st.begin(),st.end());
  st.erase(unique(st.begin(),st.end()),st.end());

  memo.clear();memo[0] = true;
  priority_queue<P2,vector<P2>,greater<P2> > q;
  q.push(P2(P(3,0),ans));

  while(q.size()){
    P2 p = q.top(); q.pop();
    
    for(int i=0;i<st.size();i++){
      tmp = p.sc;
      if(color(st[i],tmp) == 1){
	tmp &= -1LL^(3LL*st[i]);
	if(tmp==0){
	  cout << p.fs.sc + 1 << endl;
	  return 0;
	}
	if(memo.find(tmp)==memo.end()){
	  memo[tmp] = true;	  
	  q.push(P2(P(p.fs.sc+color((1LL<<32)-1,tmp)+1,p.fs.sc+1),tmp));
	}
      }
    }
  }
}
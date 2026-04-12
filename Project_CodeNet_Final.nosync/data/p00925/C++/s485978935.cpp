#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <functional>
#include <algorithm>

using namespace std;

#define rep(i,j) REP((i), 0, (j))
#define REP(i,j,k) for(int i=(j);(i)<(k);++i)
#define BW(a,x,b) ((a)<=(x)&&(x)<=(b))
#define ALL(v) (v).begin(), (v).end()
#define LENGTHOF(x) (sizeof(x) / sizeof(*(x)))
#define AFILL(a, b) fill((int*)a, (int*)(a + LENGTHOF(a)), b)
#define SQ(x) ((x)*(x))
#define Mod(x, mod) (((x)+(mod)%(mod))
#define MP make_pair
#define PB push_back
#define Fi first
#define Se second
#define INF (1<<29)
#define EPS 1e-10
#define MOD 1000000007

typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef vector<int> vi;
typedef queue<int> qi;
typedef long long ll;

ll M(string s)
{
  int p=0;
  stack<ll>st;
  int multi = 0;  
  for(int i=0;i<s.size();i++){
    if(s[i] == '+'){
      stringstream ss;
      ss << s.substr(p, i-p);
      ll x;
      ss >> x;
      if(multi){
	x *= st.top(); st.pop();
	multi = 0;
      }
      st.push(x);
      p = i+1;
    }else if(s[i] == '*'){
      stringstream ss;
      ss << s.substr(p, i-p);
      ll x;
      ss >> x;
      if(multi){
	ll t = st.top(); st.pop();
	x *= t;
	multi = 0;
      }
      st.push(x);
      p = i+1;
      multi = 1;      
    }
  }

  stringstream ss; ss << s.substr(p);
  ll x; ss >> x;
  if(multi){
    x *= st.top(); st.pop();
    multi = 0;
  }
  st.push(x);
  ll ret = 0;
  while(!st.empty()){
    ret += st.top();
    st.pop();
  }
  return ret;
}

ll L(string s)
{
  int p = 0, pe = 0;
  int mflag = 0, pflag = 0;
  ll ret = 0;
  while(pe < s.size()){
    if(s[pe] == '*'){
      stringstream ss; ss << s.substr(p, pe-p);
      ll x; ss >> x;
      if(mflag){
	ret *= x;
	mflag = 0;
      }else if(pflag){
	ret += x;
	pflag = 0;
      }else{
	ret = x;
      }
      mflag = 1;
      p = pe+1;
    }else if(s[pe] == '+'){
      stringstream ss; ss << s.substr(p, pe-p);
      ll x; ss >> x;
      if(mflag){
	ret *= x;
	mflag = 0;
      }else if(pflag){
	ret += x;
	pflag = 0;
      }else{
	ret = x;
      }      
      pflag = 1;
      p = pe+1;
    }
    pe++;
  }
  stringstream ss; ss << s.substr(p);
  ll x; ss >> x;
  if(mflag){
    ret *= x;
    mflag = 0;
  }else if(pflag){
    ret += x;
    pflag = 0;
  }else{
    ret = x;
  }
  
  return ret;
}

int main()
{
  string s;
  ll bob;  
  cin >> s >> bob;
  int Mflag = (M(s) == bob);

  int Lflag = (L(s) == bob);
  if(Mflag && Lflag) cout << 'U';
  else if (!Mflag && !Lflag) cout << 'I';
  else if(Mflag) cout << 'M';
  else cout << 'L';
  cout << endl;
  return 0;
}
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<cstdio>
#include<climits>
#include<cmath>
#include<cstring>
#include<string>
#include<sstream>
#include<numeric>
#include<cassert>

#define f first
#define s second
#define mp make_pair

#define REP(i,n) for(int i=0; i<(int)(n); i++)
#define rep(i,s,n) for(int i=(s); i<(int)(n); i++)
#define FOR(i,c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define ALL(c) (c).begin(), (c).end()
#define IN(x,s,g) ((x) >= (s) && (x) < (g))
#define ISIN(x,y,w,h) (IN((x),0,(w)) && IN((y),0,(h)))
#define print(x) printf("%d\n",x)

using namespace std;

typedef unsigned int uint;
typedef long long ll;

const int _dx[] = {0,1,0,-1};
const int _dy[] = {-1,0,1,0};

int getInt(){
  int ret = 0,c;
  c = getchar();
  while(!isdigit(c)) c = getchar();
  while(isdigit(c)){
    ret *= 10;
    ret += c - '0';
    c = getchar();
  }
  return ret;
}

int main(){
  int m,n;
  while(cin>>m>>n, m+n){
    vector<bool> f(m, true);
    int p = 0;
    int r = m;
    REP(i,n){
      int cnt = i + 1;
      string tmp;
      string ans;
      cin >> tmp;

      if(r == 1) continue;

      if(cnt % 3 == 0) ans += "Fizz";
      if(cnt % 5 == 0) ans += "Buzz";
      if(ans.size() == 0){
	char buff[256];
	sprintf(buff,"%d",cnt);
	ans = buff;
      }
      if(ans != tmp){
	f[p] = false;
	r--;
      }
      if(r != 1){
	do
	  if(++p == m) p = 0;
	while(!f[p]);
      }
    }

    bool fst = true;
    REP(i,m) if(f[i]){
      if(!fst) cout << " ";
      else fst = false;
      cout << i + 1;
    }
    cout << endl;
  }
  return 0;
}
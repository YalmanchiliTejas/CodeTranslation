#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(),(c).end()
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define iter(c) __typeof((c).begin())
#define tr(it,c) for(iter(c) it=(c).begin(); it!=(c).end(); it++)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define pr(a) cout << (a) << endl
#define F first
#define S second
typedef long long ll;
typedef pair<int,int> P;
const int MAX=2000000001;
int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};

int ch[26]={'0','0','0','0','0','0','0','1','1','1','1','1','1','1','1','1','0','0','0','0','1','0','0','0','1','0'};

int main() {
  string s;
  while(cin >> s && s!="#") {
    int a=ch[(int)s[0]-'a'];
    int cnt=0;
    rep(i,s.size()) {
      int b=ch[(int)s[i]-'a'];
      cnt+=abs(a-b);
      a=b;
    }
    pr(cnt);
  }
  return 0;
}

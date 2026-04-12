#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(),(c).end()
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define rrep(i,n) for(int i=(int)(n)-1; i>=0; i--)
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define iter(c) __typeof((c).begin())
#define tr(it,c) for(iter(c) it=(c).begin(); it!=(c).end(); it++)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define pr(a) cout << (a) << endl
#define PR(a,b) cout << (a) << " " << (b) << endl
#define F first
#define S second
typedef long long ll;
typedef pair<int,int> P;
const int MAX=1000000001;
const ll MAXL=1000000000000000001LL;
const ll mod=1000000007;
int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};

int main() {
  int n,m;
  while(cin >> n >> m && (n||m)) {
    queue<int> que;
    for(int i=1; i<=n; i++) que.push(i);
    string s;
    for(int i=1; i<=m; i++) {
      cin >> s;
      if(que.size()>1) {
	int x=que.front();
	que.pop();
	if(i%15==0) {
	  if(s!="FizzBuzz") continue;
	} else if(i%3==0) {
	  if(s!="Fizz") continue;
	} else if(i%5==0) {
	  if(s!="Buzz") continue;
	} else {
	  if(!isdigit(s[0])) continue;
	  stringstream ss;
	  ss << s;
	  int k;
	  ss >> k;
	  if(k!=i) continue;
	}
	que.push(x);
      }
    }
    vector<int> ans;
    while(!que.empty()) {
      ans.pb(que.front());
      que.pop();
    }
    sort(all(ans));
    rep(i,ans.size()) {
      if(i) cout << " ";
      cout << ans[i];
    }
    cout << endl;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vvi vector< vector<int> >
#define vi vector<int>
#define All(X) X.begin(),X.end()
#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define pi 3.14159265359
#define shosu(X) fixed << setprecision(X)
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int n,m;
vi node[8];

int solve(){
  queue<pair<vector<bool>, int>> qt;
  vector<bool> start(8);
  REP(i,8) start[i] = false;
  start[0] = true;
  qt.push(mp(start, 0));
  int ans = 0;
  for(;!qt.empty();){
	auto f = qt.front();
	qt.pop();
	auto status = f.first;
	int nowpoint = f.second;
	//cout << status << " " << nowpoint << endl;
	bool ok = true;
	REP(i,n) if(!status[i]) ok = false;
	if(ok){
	  ans++;
	  continue;
	}
	REP(i,node[nowpoint].size()){
	  int next = node[nowpoint][i];
	  if(status[next]) continue;
	  vector<bool> nextstatus = status;
	  nextstatus[next] = true;
	  qt.push(mp(nextstatus,next));
	}
  }
  return ans;
}
int main(){
  cin >> n >> m;
  REP(i,m){
	int a,b;
	cin >> a >> b;
	node[a-1].pb(b-1);
	node[b-1].pb(a-1);

  }
  cout << solve() << endl;
}


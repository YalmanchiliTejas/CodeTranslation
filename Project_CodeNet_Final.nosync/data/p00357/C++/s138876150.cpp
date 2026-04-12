#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<queue>
#include<stack>
#include<bitset>
#include<functional>
#include<map>
#include<unordered_set>
using namespace std;
/*int p = 998244353;*/
int p = 1000000007;
#define int long long
#define vel vector<long long>
#define vvel vector<vel>
#define rep(i,n) for(int i=0;i<n;i++)
#define sor(v) sort(v.begin(),v.end())
#define mmax(a,b) a=max(a,b)
#define mmin(a,b) a=min(a,b)
#define mkp make_pair
#define pin pair<int,int>
#define qin pair<int,pin>
#define V vector
#define Endl endl
#define veb vector<bool>
#define rev(s) reverse(s.begin(),s.end())
bool can_move(vel &d) {
	int n = d.size();
	int now_pot = 0;
	int now_max = 0;
	while (now_pot < n) {
		if (now_pot > now_max) { return false; }
		mmax(now_max, now_pot + d[now_pot] / 10);
		now_pot++;
	}
	return true;
}
signed main(){
	int n; cin >> n;
	vel d(n);
	rep(i, n) { cin >> d[i]; }
	if (!can_move(d)) { cout << "no" << endl; return 0; }
	rev(d);
	if (!can_move(d)) { cout << "no" << endl; return 0; }
	cout << "yes" << endl;
	return 0;
}

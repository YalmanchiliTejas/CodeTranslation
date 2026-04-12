#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <complex>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <assert.h>
#include <numeric>
#include <iomanip>
#define rep(i, a, b) for (int(i) = (a); i < (b); i++)
using namespace std;

using ll = long long;

typedef pair<int, int> P;

const int INF = 100000000;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const ll MOD = 1000000007;

ll pow_mod(ll x, ll y, ll mod)
{
	ll ans=1;
	for(;y>0;y>>=1){
		if(y&1)(ans*=x)%=mod;
		(x*=x)%=mod;
	}
	return ans;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	//問題文中の添え字が0-indexか1-indexか確認!
	while(1){
		int a;
		cin >> a;
		if(a==0){
			break;
		}
		vector<int> judge(a);
		rep(i, 0, a) cin >> judge[i];
		sort(judge.begin(), judge.end());
		int sum = judge[1];
		rep(i,2,a-1){
			sum += judge[i];
		}
		cout << sum / (a - 2) << "\n";
	}
	return 0;
}

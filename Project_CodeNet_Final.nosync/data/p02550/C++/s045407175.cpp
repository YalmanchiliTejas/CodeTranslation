#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <stack>
#include <unordered_map>
#include <map>
#include <set>
#define PI 3.14159265359
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pai;
typedef pair<ll, ll> pal;
const int MOD = 1e9+7;
const int MODD = 998244353;
const ll LLINF = 1e18;


int coun[100001];
vector<int> rec;

int main(){
	ll n, x, m;
	cin >> n >> x >> m;
	
	ll now = x;
	coun[now]++;
	bool flg = false;
	rec.push_back(now);
	for (int i = 1; i < n; i++){
		now = now * now % m;
		if (coun[now] == 2){
			flg = true;
			break;
		}
		coun[now]++;
		rec.push_back(now);
	}

	if (flg == true){
		ll before = 0;
		ll loop = 0;
		ll loop_size = 0;
		ll start_id = 0;
		for (int i = 0; i < rec.size(); i++){
			if (rec[i] == rec[rec.size()-1]){
				start_id = i;
				break;
			}
			before += rec[i];
		}
		for (int i = start_id; i < rec.size()-1; i++){
			loop_size++;
			loop += rec[i];
		}
		if (loop == 0) cout << before << endl;
		else{
			n -= start_id;
			ll ans = before + n/loop_size*loop;
			for (int i = start_id; i < start_id+n%loop_size; i++){
				ans += rec[i];
			}
			cout << ans << endl;
		}
	}else{
		ll ans = 0;
		for (int i = 0; i < n; i++){
			ans += rec[i];
		}
		cout << ans << endl;
	}

	return 0;
}
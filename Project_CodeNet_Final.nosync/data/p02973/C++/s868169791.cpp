#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;
const int BIG = 1e9 + 555;
const int maxN = 200 * 1000 + 9;

int n;
int a[maxN];
vector<int> se[maxN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;

	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	int ans = 0;
	
	for(int i = 1; i <= n; i++){
		int lo = 1, hi = ans, id = -1;
		while(lo <= hi){
			int mid = (lo + hi) / 2;
			if(se[mid].back() < a[i]){
				id = mid;
				hi = mid - 1;
			} else {
				lo = mid + 1;
			}
		}

		if(id == -1){
			ans++;
			se[ans].push_back(a[i]);
		} else {
			se[id].push_back(a[i]);
		}
	}

	cout << ans << '\n';

	return 0;
}
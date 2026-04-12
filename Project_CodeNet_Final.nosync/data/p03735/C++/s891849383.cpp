#include<bits/stdc++.h>
#define maxn 200005
#define ll long long
#define pii pair<int,int>
using namespace std;
int arr[maxn];
int cal(int n,multiset<pii> s) {
	int ret = 1234567891;
	memset(arr,-1,sizeof arr);
	int cnt = 0;
	multiset<int> done;
	while(!s.empty()) {
		pii now = *s.rbegin();
		int val = now.first , idx = now.second;
		s.erase(s.lower_bound(now));
		done.insert(val);
		if(arr[idx] == -1)
			cnt++;
		else
			done.erase(done.lower_bound(arr[idx]));
		arr[idx] = val;
			
		if(cnt == n)
			ret = min(ret,(*done.rbegin()) - (*done.begin()));
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	multiset<pii> s,done;
	for(int i=1,x,y;i<=n;i++) {
		cin >> x >> y;
		s.insert(pii{x,i});
		s.insert(pii{y,i});
	}
	int Rmax = s.rbegin()->first , Bbase = -1;
	for(pii now : s)
		if(now.second == s.rbegin()->second) {
			Bbase = now.first;
			break;
		}
	done.insert(pii{Bbase,s.rbegin()->second});
	s.erase(s.lower_bound(pii{Bbase,s.rbegin()->second}));
	s.erase(s.lower_bound(*s.rbegin()));
	
	int Bmax = Bbase;
	memset(arr,-1,sizeof arr);
	int cnt = 1;
	ll ans = 1234567891234567891ll;
	if(n == 1)
		ans = 0;
	else {
		while(!s.empty()) {
			pii now = *s.rbegin();
			int Rmin = now.first , idx = now.second;
			s.erase(s.lower_bound(now));
			if(s.empty()) {		// final case
				done.insert(pii{arr[idx],idx});
				ans = min(ans,(ll)(Rmax - Rmin) * cal(n,done));
			}
			else {
				if(arr[idx] == -1)
					cnt++;
				if(cnt == n) {
					int Bmin = s.begin()->first;
					ans = min(ans,(ll)(Rmax - Rmin) * (max(Bmax,arr[idx]) - Bmin));
				}
				
				if(arr[idx] == -1)
					arr[idx] = Rmin;
				else
					Bmax = max(Bmax,Rmin);
			}
			done.insert(now);
		}
	}
	cout << ans << endl;
	return 0;
}

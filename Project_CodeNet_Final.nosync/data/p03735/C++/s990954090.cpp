#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define maxn 200005
using namespace std;
struct ball {
	int x,y;
}arr[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++) {
		cin >> arr[i].x >> arr[i].y;
		if(arr[i].x > arr[i].y)
			swap(arr[i].x,arr[i].y);
	}
	sort(arr+1,arr+1+n,[=](ball a,ball b)->bool
		{return a.x < b.x;});
	multiset<int> R,B;
	for(int i=1;i<=n;i++) {
		R.insert(arr[i].x);
		B.insert(arr[i].y);
	}
	ll ans = (ll)(*R.rbegin() - *R.begin()) * (*B.rbegin() - *B.begin());
	for(int i=1;i<=n;i++) {
		R.erase(R.lower_bound(arr[i].x));
		B.insert(arr[i].x);
		B.erase(B.lower_bound(arr[i].y));
		R.insert(arr[i].y);
		ans = min(ans,(ll)(*R.rbegin() - *R.begin()) * (*B.rbegin() - *B.begin()));
	}
	cout << ans << endl;
	return 0;
}

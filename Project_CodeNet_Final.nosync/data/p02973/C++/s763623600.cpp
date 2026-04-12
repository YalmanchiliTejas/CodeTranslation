#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;
double k[maxn];
ll a[maxn];
ll ans = 0;
int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	multiset<ll>st;
	for (int i = 0; i < n; i++){
		auto it = st.lower_bound(a[i]);
		if (it == st.begin()) st.insert(a[i]);
		else {
			it--;
			st.erase(it);
			st.insert(a[i]);
		}
	}
	cout << st.size() << endl;
	return 0;
}

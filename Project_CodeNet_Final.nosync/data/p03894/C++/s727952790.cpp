#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

signed main(){
	int n,q,p[100010],tmp = 0;
	set<int> st;
	cin >> n >> q;
	st.insert(0);
	for(int i = 0;i < n;i++) p[i] = i;
	for(int i = 0;i < q;i++){
		int a,b;
		cin >> a >> b; a--;b--;
		if(tmp >= 1) st.insert(p[tmp - 1]);
		if(tmp < n - 1) st.insert(p[tmp + 1]);
		if(tmp == a) tmp = b;
		else if(tmp == b) tmp = a;
		swap(p[a],p[b]);
	}
	if(tmp >= 1) st.insert(p[tmp - 1]);
	if(tmp < n - 1) st.insert(p[tmp + 1]);
	cout << st.size() << endl;
	return 0;
}
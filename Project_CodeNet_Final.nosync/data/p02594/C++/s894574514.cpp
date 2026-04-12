#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n; cin>>n;
	cout << ((n>29)?"Yes\n":"No\n");
}

int main(){
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t=1;
	//cin>>t;
	int cs = 1;
	while(t--){
		//cout << "Case #" << cs << ":\n";
		solve();
		cs++;
	}
	return 0;
}


#include <bits/stdc++.h>
#define read(arr,n)	for(int i=0;i<n;i++) cin>>arr[i];
#define print(arr,n) for(int i=0;i<n;i++) cout << arr[i]<<' ';cout << endl;
typedef int int32;
#define int ll

using namespace std;

typedef long long ll;

void solve() {
	string s;	cin >> s;
	if (s == "AAA" || s == "BBB") {
		cout << "No\n";
	} else {
		cout << "Yes\n";
	}
}

int32 main() {
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();	
	}
	return 0;
}

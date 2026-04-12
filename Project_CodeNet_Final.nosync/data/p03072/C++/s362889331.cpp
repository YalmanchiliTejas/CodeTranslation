#include <bits/stdc++.h>
using namespace std;

int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

 //    #ifndef ONLINE_JUDGE
	// 	freopen("../../a.in","r",stdin);
	// 	freopen("../../a.out","w",stdout);
	// #endif

	int n, x, ct=1;
	cin >> n;
	cin >> x;
	int mx = x;
	for (int i=1; i<n; i++){
		cin >> x;
		if (x>=mx){
			mx = x;
			++ct;
		}
	}
	cout << ct << "\n";
}
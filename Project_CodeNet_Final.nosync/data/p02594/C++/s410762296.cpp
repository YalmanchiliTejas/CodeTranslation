#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

void test_case(){
	int t;
	cin >> t;
	if(t>=30 ) cout <<"Yes" << endl;
	else cout << "No" << endl;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int t=1;
	// cin >> t;

	while(t--) test_case();
	
	return 0;
}


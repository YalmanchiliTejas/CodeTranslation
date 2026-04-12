#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	string s; cin>>s;	
	int n=s.size();
	for (int i=0; i<n; i++) {
		if (s.substr(i,2)=="AC") { 
			cout<<"Yes\n"; 
				return 0;
		}
	}
	cout<<"No\n";
	return 0;
}

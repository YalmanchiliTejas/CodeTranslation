#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int x;
	cin >> x;
	if(x >= 30){
		cout << "Yes\n";
	}	
	else cout << "No\n";
	return ;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
		
	int t = 1;

	while(t--){
		solve();
	}

	return 0;
}
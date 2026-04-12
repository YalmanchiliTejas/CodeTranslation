#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define mp make_pair
#define inf 1000000007
#define LINF 10000000000000007LL
#define ll long long
using namespace std;
signed main(){
	int n;
	cin>>n;
	vector<int> a;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		a.pb(x);
	}
	int ans = 0;
	multiset<int> s;
	for(int i=0;i<n;i++){
		multiset<int>::iterator it = s.upper_bound( -a[i] );
		if( it != s.end() ){
			s.erase(it);
			s.insert(-a[i]);
		}
		else{
			ans++;
			s.insert(-a[i]);
		}
	}
	cout<<ans<<endl;	
	return 0;
}
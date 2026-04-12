#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
typedef long long int ll;
multiset<int> s;
int main()
{

	ios_base:: sync_with_stdio(false); cin.tie(0);
	int n; cin>>n;
	for(int i=1; i<=n; i++) {
		int x; cin>>x;
		auto it = s.lower_bound(x);
		if(it!=s.begin()) {
			it--;
			s.erase(it);
		}
		s.insert(x);
	}
	cout<<(int)s.size()<<endl;
	return 0;
}

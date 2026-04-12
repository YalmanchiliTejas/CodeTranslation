#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int main()
{
	IO_OP;
	
	multiset<int> s;
	int n;
	cin >> n;
	for(int i=0;i<n;i++) {
		int t;
		cin >> t;
		if(s.size() && s.lower_bound(t)!=s.begin())
			s.erase(prev(s.lower_bound(t)));
		s.insert(t);
	}
	cout << s.size() << endl;
	
}


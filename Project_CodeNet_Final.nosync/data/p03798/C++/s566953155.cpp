#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define sz(v) (int)((v).size())
#define pb push_back

typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	vector<int> v(n);
	string s; cin >> s;
	for (int i=0; i<4; i++){
		v[0] = i%2;
		v[1] = i/2;
		for (int j = 2; j < n; j++) {
			v[j] = (s[j-1]=='o')^v[j-2]^v[j-1];
		}

		if( ( (v[0]^v[1]^(s[0]=='o')) == v[n-1]) && ( ((v[n-2]^v[n-1]^(s[n-1]=='o'))&1) == v[0]) ){
			for (int i = 0; i < n; i++) {
				cout << "WS"[v[i]];
			}
			cout << "\n";
			//cout << ( (v[0]^v[1]^(s[0]=='o')) == v[n-1]) <<" "<< ( (v[n-2]^v[n-1]^(s[n-1]=='o')) == v[0]) << "\n";
			return 0;
		}
	}
	cout << "-1\n";
}

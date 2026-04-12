#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int n;
	cin>>n;
	vector<int> f(26, 50);
	for(int i = 0; i < n; i++){
		string s;
		cin>>s;
		vector<int> g(26, 0);
		for(auto ch : s){
			g[ch - 'a']++;
		}
		for(int i = 0; i < 26; i++){
			f[i] = min(f[i], g[i]);
		}
	}
	for(int i = 0; i < 26; i++){
		for(int j = 0; j < f[i]; j++){
			cout<<char(i + 'a');
		}
	}
	cout<<'\n';

	return 0;
}
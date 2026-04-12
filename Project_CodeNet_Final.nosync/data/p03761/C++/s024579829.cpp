#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<map>
#define rep(i,n) for(int i=0;i<n;++i)
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl
#define mod 1000000007
using namespace std;
using ll = long long;
int main() {
	int n;	cin >> n;
	vector<string> S(n);
	vector<int> Spos(n);
	string ans;
	int shortest = mod;
	rep(i, n) {
		cin >> S[i];
		if (shortest > S[i].size())shortest = S[i].size();
		sort(S[i].begin(), S[i].end());
	}
	bool loop = true;
	while(loop) {
		char c = S[0][Spos[0]];
		char bigC = c;
		bool ok = true;
		rep(j, n) {
			if (c != S[j][Spos[j]]) ok = false;
			if (bigC < S[j][Spos[j]]) bigC = S[j][Spos[j]];
		}

		if (ok) {
			ans += c;
			rep(j, n) {
				Spos[j] += 1;
				if (Spos[j] >= S[j].size()) loop = false;
			}
		}
		else {
			rep(j, n) {
				if (bigC > S[j][Spos[j]]) Spos[j] += 1;
				if (Spos[j] >= S[j].size()) loop = false;
			}
		}
	}
	if (ans.size() > 0) {
		cout << ans << endl;
	}
	else {
		cout << endl;
	}
}

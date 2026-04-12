#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;
// const ll INF = 1000000000000000000LL;

int main() {
	int n;
	string s;
	int k;
	cin >> n >> s >> k;
	char k_s = s[k-1];
	rep(i,s.size()){
		if(s[i]!=k_s)
			s[i] = '*';
	}
	cout << s << endl;
	return 0;
}


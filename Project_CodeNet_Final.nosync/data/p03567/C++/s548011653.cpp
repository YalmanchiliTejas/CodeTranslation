#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
#ifdef LOCAL
	std::ifstream in("in");
	std::cin.rdbuf(in.rdbuf());
#endif

	string s;
	cin >> s;
	if(s.find("AC") != string::npos) cout << "Yes" << endl;
	else cout << "No" << endl;
}

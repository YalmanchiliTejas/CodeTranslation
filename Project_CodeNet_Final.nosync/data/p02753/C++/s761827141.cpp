
// A - Station and Bus

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main(){
	string S;
	cin >> S;

	string ans;

	if (S[0] == S[1] && S[1] == S[2]) ans = "No";
	else ans = "Yes";

	cout << ans << endl;

	return 0;
}
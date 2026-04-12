#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

	string s;
	cin >> s;
	sort(s.begin(), s.end());
	if(s[0] != s[2]) cout << "Yes";
	else cout << "No";
    return 0;
}

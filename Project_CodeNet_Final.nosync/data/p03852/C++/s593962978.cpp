#include <bits/stdc++.h>
using namespace std;

int main(){
#ifdef _DEBUG
	freopen("in" , "r", stdin );
	freopen("out", "w", stdout);
#endif
	ios::sync_with_stdio(0); cin.tie(0);
	vector<char> s = {'a', 'e', 'i', 'o', 'u'};
	char c; cin >> c;
	if(find(s.begin(), s.end(), c) != s.end()) cout << "vowel\n";
	else cout << "consonant\n";
}

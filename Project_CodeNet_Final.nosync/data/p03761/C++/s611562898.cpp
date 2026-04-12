#include	<bits/stdc++.h>
using	namespace	std;

// int/long:		-2147483648 - 2147483648 (-2^31 <= int < 2^31)
// long/long long:	-9223372036854775808 - 9223372036854775807 (-2^63 <= long < 2^63)
#define	INF (1<<29)
//536870912

#define	MOD 1000000007

int	main() {
	int n;
	cin >>n;
	vector<int> a(26, 50);
	for (int i=0; i<n; i++) {
		vector<int> aa(26, 0);
		string S;
		cin >>S;
		for (int j=0; j<S.size(); j++) {
			int c=S.at(j)-'a';
			aa.at(c)++;
		}
		for (int j=0; j<26; j++)
			a.at(j)=min(a.at(j), aa.at(j));
	}
	string SS="";
	for (int i=0; i<26; i++) {
		for (int j=0; j<a.at(i); j++)
			SS.push_back('a'+i);
	}
	cout <<SS <<endl;
	return 0;
}

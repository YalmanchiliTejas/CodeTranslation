#include	<bits/stdc++.h>
using	namespace	std;
typedef	long long ll;

#define	Rep0(i, n)	for (int i=0; i<n; i++)
#define	Rep1(i, n)	for (int i=1; i<=n; i++)
#define Sort(P)	sort(P.begin(), P.end())
#define Rev(P)	reverse(P.begin(), P.end())

int	main() {
	string S;
	cin >>S;
	for (int i=1; i<S.size(); i++)
		if (('A'==S.at(i-1))&&('C'==S.at(i))) {
			cout <<"Yes" <<endl;
			return 0;
		}
	cout <<"No" <<endl;
	return 0;
}


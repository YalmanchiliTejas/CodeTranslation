#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define repd(i,a,b) for (int i = (a); i < (b); i++)
#define INF LLONG_MAX
#define mod 1000000007
typedef long long ll;
int main(void)
{
	string S;
	cin >> S;
	int A=0, B=0;
	rep(i, S.size())
	{
		if(S.at(i)=='A') A++;
		else B++;
	}
	if(A==0 || B==0) cout << "No" << endl;
	else cout << "Yes" << endl;
	return 0;
}

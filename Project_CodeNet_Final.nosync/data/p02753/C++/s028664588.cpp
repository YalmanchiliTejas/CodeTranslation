#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
#define ll long long

int main()
{
	string S;
	cin >> S;
	
	if ( S[0] == S[1] && S[1] == S[2] )
	{
		cout << "No";
	}
	else
	 cout << "Yes";
}
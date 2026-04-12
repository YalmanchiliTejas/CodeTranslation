#include <bits/stdc++.h>

#define FAST_IO                       \
	ios_base::sync_with_stdio(false); \
	cin.tie(0);                       \
	cout.tie(0);

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

const int MOD = 1e9 + 7;

int main()
{

	FAST_IO;

	
	string s;
	cin>>s;
	if(s == "AAA" || s == "BBB")
		cout<<"No";
	else
		cout<<"Yes";
	return 0;
}

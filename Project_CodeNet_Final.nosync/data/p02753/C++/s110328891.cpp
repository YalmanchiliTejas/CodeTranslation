#include <bits/stdc++.h>

using namespace std;
#define f first
#define s second
//#define int long long
#define st string
#define int long long
#define dear_crush int32_t main()
#define bari_ja return 0
#define forn(i, n) for (int i = 0; i < n; i++)
#define INF 1e9+5

dear_crush
{

string str;

cin >> str;

	bool flag = true;
	int c=0;

for(int i=0; i<str.size(); i++){

	if (str[i]=='A') {
		c++;
	}
}

if (c!=0 && c<3) {

	std::cout << "Yes" << '\n';
}

else
std::cout << "No" << '\n';





bari_ja;
}

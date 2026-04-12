/*suri_kumkaran*/

#include <bits/stdc++.h>

using namespace std;

#define UB upper_bound
#define LB lower_bound
#define BS binary_search
#define MP make_pair
#define EB emplace_back
#define endl "\n"
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define F first
#define S second
#define ALL(a) (a).begin(),(a).end()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long

typedef long long int64;
typedef vector<int> VI64;
typedef vector<pair<int,int>> VII64;
typedef vector<string> VS;
typedef vector<vector<int>> VVI;

int32_t main()
{
	IOS;
	int T=1;
	//cin>>T;
	while(T--)
	{
		string s;
		cin>>s;
		if(count(ALL(s),'A')&&count(ALL(s),'B'))
			cout<<"Yes";
		else
			cout<<"No";
		cout<<endl;
	}

	return 0;
}
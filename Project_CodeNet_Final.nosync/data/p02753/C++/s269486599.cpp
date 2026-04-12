#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long
#define watch(x) cout << (#x) << " is " << (x) << endl

typedef vector<int> vi;
typedef vector< vi > vvi;
typedef pair< int,int > ii;
typedef pair< double,double> dd;
#define pb push_back
#define eb emplace_back
#define sz(a) int((a).size))
#define all(c) c.begin(),c.end()
#define FOR(i,a,b) for(i=a; i<b; i++)
#define FORR(i,a,b) for(i=a;i>=b;i--)
#define REP(i,n) FOR(i,0,n)
#define x first
#define y second
#define mp make_pair

const int INF = 1000000007;
const long long INFLL = (ll)INF * (ll)INF;
 
int32_t main()
{
	IOS;
	string s;
	int flaga=0,flagb=0;
	cin>>s;
	for(int i=0;i<(int)s.length();i++)
	{
		if(s[i]=='A')
		{
			flaga=1;
		}
		else
		{
			flagb=1;
		}
	}
	if((flaga==1) && (flagb==1))
	{
		cout<<"Yes";
	}
	else
	{
		cout<<"No";
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

typedef vector<int > vi;
typedef vector< vi > vvi;
typedef pair< int, int > ii;
#define sz(a)  int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define forn(i,n) for(int i=0;i<n;++i)
#define foru(i,n) for(int i=1;i<=n;++i)
#define fortr(i,v) for(auto &i:v)
#define set(n) __builtin_popcount(n)
#define ll long long
#define MOD 1000000007

int main()
{
	ll n,m;
	cin>>n>>m;
	if(n==m)
		cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
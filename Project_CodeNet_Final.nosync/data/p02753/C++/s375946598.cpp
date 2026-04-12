#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl 	"\n"

typedef vector< ll > 	vi;
typedef vector< vi > 	vvi;
typedef pair< ll,ll > 	ii;

#define pb 		push_back
#define all(c) 		(c).begin(),(c).end()
#define present(c,x) 	((c).find(x) != (c).end())
#define rep(i,n)        for(ll i=0LL; i<(n); i++)

#define MOD 	1000000007
#define INF 	(int)1e9
#define MEM(a, b) memset(a, (b), sizeof(a))

//Maths functions
ll Digit(ll N){ll res=0;while(N) res++, N/=10;return res;}
ll Gcd(ll a,ll b){ return b?Gcd(b,a%b):abs(a); }


int main()
{	 ios_base::sync_with_stdio(false);
	 cin.tie(NULL);
	
	string s;
	cin>>s;
	set<char> sp;
	for(ll i=0; i<3; i++)
		sp.insert(s.at(i));
	if(sp.size()==1)
		cout<<"No";
	else cout<<"Yes";
	
	return 0;
}
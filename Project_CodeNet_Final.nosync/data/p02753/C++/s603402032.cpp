/* Author - thiolhub */

#include <bits/stdc++.h>

using namespace std;

#define ll              long long int
#define ld              long double
#define db              double
#define pi              3.1415926535897932384626
#define PI              acos(-1.0)
#define endl            "\n"
#define mod             1000000007
#define mk              make_pair
#define pb              push_back
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define ps(x,y)         fixed<<setprecision(y)<<x
#define w(t)            ll t; cin>>t; while(t--)
#define sc(a)	        scanf("%lld",&a);
#define pr(a)	        printf("%lld\n",a)
#define f(i,a,n)		for(ll i=a;i<n;i++)
#define m(a)		    memset(a,0,sizeof(a))
#define FastIO          ios_base::sync_with_stdio(0);cin.tie(0),cout.tie(0)



int main(){ FastIO;

string s;cin>>s;
int p=0,q=0;
for(int i=0;i<3;i++){
	if(s[i]=='A') p++;
	else q++;
}
if(p>0 && q>0) cout<<"Yes";
else cout<<"No";

return 0;
}
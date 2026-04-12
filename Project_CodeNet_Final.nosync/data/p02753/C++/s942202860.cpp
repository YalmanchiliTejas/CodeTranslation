#include<bits/stdc++.h>
#define ll long long int
#define M 1000000007
#define mod 998244353
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define pi pair<ll,ll>
using namespace std;
const ll N=500010;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin>>s;
	set<char> ss;
	for(ll i=0;i<3;++i)
    {
        ss.insert(s[i]);
    }
    if(ss.size()==2){cout<<"Yes";}
    else{cout<<"No";}

	return(0);
}

//srinivas
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
//#include <boost/multiprecision/cpp_int.hpp>
//using namespace boost::multiprecision;
// using namespace __gnu_pbds;
using namespace std;

#define all(c) (c).begin(),(c).end()
#define endl "\n"
#define ff first
#define ss second
#define allr(c) (c).rbegin(),(c).rend()
#define fr(x,in,n,r) for(x=in;x<n;x+=r)
#define ifr(x,n) for(x=0;x<n;x++)
#define dfr(x,n) for(x=n-1;x>=0;x--)
#define pb(a) push_back(a)
#define pf(a) push_front(a)
#define pof(a) pop_front(a)
#define pob(a) pop_back(a)
#define eb(a) emplace_back(a)
#define ef(a) emplace_front(a)
typedef long long ll;
typedef map<ll,ll> mll;
typedef map<string,ll> msll;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef long double ld;
#define mod 1000000007

struct chash{ 
    ll operator()(ll x) const {return hash<ll>{}(x);}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt","r",stdin);
    ll n,k;
    cin>>n;
    string s;
    cin>>s;
    ll i,j;
    cin>>k;
    ifr(i,s.length()){
    	if(s[i]!=s[k-1])
    		cout<<"*";
    	else
    		cout<<s[i];
    }
    cout<<endl;
	return 0;
}
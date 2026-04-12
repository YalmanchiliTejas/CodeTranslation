#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<string>vst;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;

#define fastio ios_base::sync_with_stdio(false);cin.tie(0)
#define all(ct) ct.begin() , ct.end()
#define endl "\n"
#define fr(i,a) for(auto i:a)
#define f(i,a,b) for(int i=a;i<b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define pb push_back
#define in(d,v) d.find(v)!=d.end()
#define mp make_pair
#define size(a) int(a.size())

const int mod = 1e9 + 7;
const ll inf = ll(1e18);
const double PI = acos(-1);

ll modexp(ll x,ll n,int md){
    if(n==0)return 1;
    if(n%2==0)return modexp((x*x)%md,n/2,md);
    return (x*modexp((x*x)%md,n/2,md))%md;
}

int main(){
    fastio;
    //clock_t tm = clock();
    string s;
    cin>>s;
    if(s=="AAA" or s=="BBB"){
        cout<<"No"<<endl;
    }
    else{
        cout<<"Yes"<<endl;
    }
    //cout<<((clock()-tm)*1.0)/CLOCKS_PER_SEC<<endl;
}
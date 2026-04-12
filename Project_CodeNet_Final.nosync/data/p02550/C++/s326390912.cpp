#include <bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds;   
#define ll long long
#define ull unsigned long long
#define ld long double
// #define ordered_set tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update> 
// ll mod=1e9+7;
ll mod2=998244353;
#define PI 3.1415926535897932385
#define inf 9e18
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
string char_to_str(char c){string tem(1,c);return tem;}
typedef pair<long long, long long> ii;
#define S second
#define F first
ll max(ll a,ll b){if(a>b){return a;}return b;}
ll min(ll a,ll b){if(a<b){return a;}return b;}
#define MAXN 200005
// Comment this out for interactive problem
// #define endl '\n'
// string to integer stoi() Remember: it takes string not character
// string to long long stoll()
// string.substr(position,length);
// integer to string to_string();
 
// To compile--> g++ -std=c++0x -o output one.cpp
// To run--> ./output
ll power(ll x, ll y, ll p){
    ll res=1;
    while(y>0){
        if(y%2==1){
            res = (res*x)%p;
        }
        x = (x*x)%p;
        y=y/2;
    }
    return res;
}

int main(){ 
    fastio;
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    ll n,x,m;
    cin>>n>>x>>m;

    set<ll> s1;
    vector<ll> v;
    s1.insert(x);
    v.push_back(x);
    ll pow1=2;
    ll num=x;
    ll ans=x;
    ll left=n-1;

    while((s1.find(power(num, pow1, m))==s1.end()) && (left!=0)){
        num = power(num, pow1, m);
        s1.insert(num);
        v.push_back(num);
        ans+=num;
        left--;
    }

    if(left==0){
        cout<<ans;
        return 0;
    }

    num = power(num, pow1, m);
    vector<ll> v1;
    ll ind=0;
    for (int i = 0; i < v.size(); ++i)
    {
        if(v[i]==num){
            ind=i;
            break;
        }
    }

    for (int i = ind; i < v.size(); ++i)
    {
        v1.push_back(v[i]);
    }

    ll sum=0;
    for (int i = 0; i < v1.size(); ++i)
    {
        sum+=v1[i];
    }
    ll q = left/v1.size();
    ll r = left%v1.size();

    ans = ans + (sum*q);

    for (int i = 0; i < r; ++i)
    {
        ans+=v1[i];
    }
    cout<<ans;

    return 0;
}

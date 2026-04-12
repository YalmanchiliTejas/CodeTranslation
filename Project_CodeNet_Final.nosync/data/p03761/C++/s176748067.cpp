#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define leadinz zero str.erase(0, min(str.find_first_not_of('0'), str.size()-1));
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
string text="abcdefghijklmnopqrstuvwxyz";
const int maxn=1e6+7;
//        .--------------.
//        | Try First One|
//        '--------------'
//                |     .--------------.
//                |     |              |
//                V     V              |
//              .--------------.       |
//              |      AC.     |<---.  |
//              '--------------'    |  |
//              (True)|  |(False)   |  |
//           .--------'  |          |  |
//           |           V          |  |
//           |  .--------------.    |  |
//           |  |   Try Again  |----'  |
//           |  '--------------'       |
//           |                         |
//           |  .--------------.       |
//           '->| Try Next One |-------'
//              '--------------'
ll bin_pow(ll a,ll b,ll m)
{
    ll res=1;
    a%=m;
    while(b>0){
        if(b&1)res=res*a%m;
        b>>=1;
        a=a*a%m;
    }
    return res;
}
bool miller_rabin(ll d,ll n)
{
    ll a=2+rand()%(n-4);
    ll x=bin_pow(a,d,n);
    if(x==1 || x==n-1)return true;
    while(d!=n-1){
        x=(x*x)%n;
        d*=2;
        if(x==1)return false;
        if(x==n-1)return true;
    }
    return false;
}
bool prime(ll n,ll k)
{
    if(n==1 || n==4)return false;
    if(n<=3)return true;
    ll d=n-1;
    while(d%2==0)d/=2;
    for(int i=0;i<k;i++){
        if(!miller_rabin(d,n))return false;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int>v(26,100005);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        vector<int>cnt(26,0);
        for(auto x: s)cnt[x-'a']++;
        for(int i=0;i<26;i++)v[i]=min(v[i],cnt[i]);
    }
    for(int i=0;i<26;i++){
        string k(v[i],i+'a');
        cout<<k;
    }
}

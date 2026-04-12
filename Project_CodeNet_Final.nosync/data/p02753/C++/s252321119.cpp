#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int mod=1e9+7;
//const int mod=998244353;
const double eps = 1e-10;
const double pi=acos(-1.0);
const int maxn=1e5+10;
const ll inf=0x3f3f3f3f;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    string s;
    cin>>s;
    int a=0,b=0;
    for(int i=0;i<s.length();i++)
        if(s[i]=='A')a++;
        else b++;
    if(a&&b)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define pll pair<long long,long long>
#define pdd pair<long double,long double>
#define vll vector<ll>
#define rep(i,j,n) for(int i=j;i<n;i++)
#define mp make_pair
#define pb push_back
#define pf push_front
#define inf 1e17
priority_queue<pll,vector<pll>,greater<pll> >pq;
priority_queue<ll,vector<ll>,greater<ll> >pq1;

ll result(ll a, ll b, ll p){
    ll ans=1;
    if(b==(-1))
        b=p-2;
    while(b){
        if(b&1){
            ans=(ans*a)%p;
        }
        a=(a*a)%p;
        b>>=1;
    }
    return ans;
}

int main(){
    if(fopen("input.txt", "r"))
    freopen("input.txt", "r", stdin),
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    if(s=="AAA" || s=="BBB")
        cout<<"No\n";
    else
        cout<<"Yes\n";


    return 0;
        
}

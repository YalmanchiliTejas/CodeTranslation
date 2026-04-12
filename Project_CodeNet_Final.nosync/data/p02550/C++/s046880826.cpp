#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#define fio freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define dsc [](int a,int b)->bool {return a>b;}
#define pb push_back
#define test int t; cin>>t;
#define MOD 998244353LL
#define all(x) (x).begin(),(x).end()

using namespace std;

ll nxt() { ll x; cin>>x; return x; }

int main()
{
    #ifndef ONLINE_JUDGE
        fio
    #endif
    IOS

    ll n,x,m;
    cin>>n>>x>>m;
    ll sum = 0;
    map<ll,bool>mm;
    vector<ll> mod;
    mod.pb(x);
    mm[x] = true;
    ll f = -1;
    bool cal = false;
    for(int i = 1; i<n; i++){
        x = x*x;
        x %= m;
        if(mm[x]){
            f = x;
            cal = true;
            break;
        }
        mm[x] = true;
        mod.pb(x);
    }
    if(cal){
    ll tmp = 0;
    bool add = false;
    ll nn = 0;
    int st = -1;
    for(int i = 0; i<mod.size(); i++){
        if(mod[i] == f){
            st = i;
            add = true;
        }
        if(add){
            tmp+=mod[i];
            nn++;
        }
        else{
            n--;
            sum+=mod[i];
        }
    }

    sum+=(n/nn) * tmp;
    n = n%nn;
    for(int i = st, j = 0; j<n; j++,i++){
        sum+=mod[i];
    }
    cout<<sum<<endl;
    }
    else{
        sum = 0;
        for(ll x: mod) sum+=x;
        cout<<sum<<endl;
    }

    return 0;
}

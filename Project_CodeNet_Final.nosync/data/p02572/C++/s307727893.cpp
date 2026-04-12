#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define pii pair<int,int>
#define IOS ios::sync_with_stdio(0); cin.tie(0);
#define fio freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define vll vector<long long int>
#define vpii vector<pair<int,int>>
#define dsc [](int a,int b)->bool {return a>b;}
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define MAX 1000000000000000000
#define test int t; cin>>t;
#define MOD 1000000007LL
#define all(x) (x).begin(),(x).end()

using namespace std;

ll nxt(){
    ll x;
    cin>>x;
    return x;
}

int main()
{
    #ifndef ONLINE_JUDGE
        fio
    #endif
    IOS
    
    ll n = nxt();
    vector<ll>a(n);
    generate(all(a),nxt);
    vector<ll>sum(n);
    ll pre = 0;
    for(int i = n-1; i>=0; i--){
        sum[i] = pre+a[i];
        pre = sum[i];
    }

    ll res = 0;

    for(int i = 0; i<n-1; i++){
        ll tmp = ((a[i]%MOD) * (sum[i+1]%MOD))%MOD;
        res = ((res%MOD)+(tmp%MOD))%MOD;
    }

    cout<<res<<endl;

    return 0;
}
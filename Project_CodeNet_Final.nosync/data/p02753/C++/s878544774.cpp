    #include <bits/stdc++.h>
    using namespace std;
    
    typedef double dd;
    typedef long long ll;

    #define all(v) v.begin(),v.end()
    #define rall(v) v.rbegin(),v.rend()
    #define trav(i,a) for(auto i: a)
    #define ff first
    #define ss second
    #define eb emplace_back
    #define tc(t) ll t; cin>>t; while(t--)
    #define prec(n) fixed<<setprecission(n)
    #define mst(arr,value) memset(arr,value,sizeof(arr))
    
    const long long sz = (long long)1e5;
    const long long mx = (long long)2e5+5;
    const long long inf = (long long)1e18;
    const long long mod = (long long)1e9+7;
    
    #define f(i,n)     for(ll i=0;   i<n;  i++)
    #define fab(i,a,b) for(ll i=a;   i<b;  i++)
    #define fr(i,n)    for(ll i=n-1; i>=0; i--)
    #define fba(i,b,a) for(ll i=b-1; i>=a; i--)

    long long pw(long long x,unsigned long long y) { 
        if (y==0) return 1; 
        else if (y%2==0)  return pw(x,y/2)*pw(x,y/2); 
        else return x*pw(x,y/2)*pw(x,y/2);
    }
    ll comp(pair<string, ll> &a, pair<string, ll> &b) {
        if(a.ff == b.ff) {
            if(a.ss < b.ss) return 1;
            else return 0;
        }
        if(a.ff < b.ff)return 1;
        else return 0;
    }
    int main() {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        cout.tie(NULL);
        string s;
        cin >> s;
        map<char, ll> mp;
        f(i, 3) mp[s[i]]++;
        if(mp['A'] == 0 or mp['B'] == 0) cout << "No";
        else cout << "Yes";
        return 0;
    }
#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define start_routine() int begtime = clock();
#define end_routine() int endtime = clock(); cerr << endl << "Time elapsed: " << (endtime - begtime)*1000/CLOCKS_PER_SEC << " ms"; return 0
#define speed() cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(false)
// #define exit(a, b) return cout << a, b;

#define loop(i,a,b) for(ll i=a;i<b;i++)
#define all(v) v.begin(), v.end() 

#define print(stuff) cout << stuff << endl
#define len length
#define ret0 return 0
#define ret return 

#define ll long long
#define ld long double
#define fi first
#define endl '\n'
#define se second
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound

#define vl vector<ll> 
#define sl set<ll>
#define pll pair<ll, ll>
#define mll map<ll, ll> 
#define pq priority_queue<ll>

// typedef tree<ll,null_type,less<ll>,rb_tree_tag,
// tree_order_statistics_node_update> indexed_set;

#define inf (long long int) 1e18
#define eps 0.000001
#define mod 1000000007
#define mod1 998244353
#define MAXN 10000

ll modexp(ll a, ll b, ll m){
    if (b==0)
        return 1;
    ll temp = modexp(a,b/2,m);
    temp = (temp*temp)%m;
    if (b&1)
        return (temp*(a%m))%m; // if b is odd a^b = a^(b/2)*a^(b/2)*a
    return temp;
}


string k;
ll d;
ll dp[10004][2][103];

ll f(ll i, ll b, ll rem){ // b=0 means that it has not yet become smaller.
    if(i>=MAXN){
        if(rem==0) return 1;
        else if(rem!=0) ret 0;
    }
    else if(dp[i][b][rem]!=-1){
        ret dp[i][b][rem];
    }
    else {
        ll ans = 0;
        if(b==0){
            ll dig_k = k[i]-'0';
            loop(j,0,dig_k){
                ll new_rem = (rem + (j)%d)%d;
                ans = (ans%mod + f(i+1, 1, new_rem)%mod)%mod;
            }
            ll neww_rem = (rem + (dig_k)%d)%d;
            ans = (ans%mod + f(i+1, 0, neww_rem)%mod)%mod;
        }
        else if(b==1){
            loop(j,0,10){
                ll new_rem = (rem + (j)%d)%d;
                ans = (ans%mod + f(i+1, 1, new_rem)%mod)%mod;
            }
        }
        ret dp[i][b][rem] = ans%mod;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   

    cin>>k;
    cin>>d;
    string temp;
    loop(i,0,MAXN-k.len()){
        temp.pb('0');
    }
    loop(i,0,k.len()) temp.pb(k[i]);
    k=temp;
    loop(i,0,10004){
        loop(j,0,2){
            loop(k,0,103){
                dp[i][j][k]=-1;
            }
        }
    }
    ll op = (f(0, 0, 0)%mod - 1 + mod)%mod;
    print(op);

        
    
}


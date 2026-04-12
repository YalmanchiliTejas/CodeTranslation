#include<iostream>
#include<iomanip>
#include<cstdio>
#include<string>
#include<cstring>
#include<climits>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<deque>
#include<tuple>
#include<list>
#include<unordered_map>
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<int>
#define vll vector<ll>
#define lb lower_bound
#define pb push_back
#define mp make_pair
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep2(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,n) for(ll i=n-1;i>=0;i--)
#define all(x) x.begin(),x.end()
#define INF (1 << 30) - 1
#define LLINF (1LL << 61) - 1
// #define int ll
using namespace std;
const int MOD = 1000000007;
const int MAX = 510000;



int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,a[100010];
    cin >> n;
    rep(i,n){
        cin>>a[i];
    }
    multiset<ll> se;
    rep(i,n)
    {
        if (se.lower_bound(a[i]) != se.begin())
        {
            se.erase(prev(se.lower_bound(a[i])));
        }
        se.insert(a[i]);
    }
    cout << se.size() << endl;
    return 0;
}
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
    ll n,a[100010],ans=0,left;
    deque<ll> deq;
    map<ll,ll> mp;
    cin>>n;
    rep(i,n){
        cin>>a[i];
        mp[a[i]]++;
    }
    sort(a,a+n);
    rep(i,n-1){
        if(i%4==0){
            deq.push_back(a[n-(i/2+1)]);
            mp[a[n-(i/2+1)]]--;
        }
        else if(i%4==1){
            deq.push_front(a[i/2]);
            mp[a[i/2]]--;
        }
        else if(i%4==2){
            deq.push_back(a[i/2]);
            mp[a[i/2]]--;
        }
        else{
            deq.push_front(a[n-(i/2+1)]);
            mp[a[n-(i/2+1)]]--;
        }
    }
    for(auto i:mp){
        if(i.second>0) left=i.first;
    }
    rep(i,n-2){
        ans+=abs(deq.at(i)-deq.at(i+1));
    }
    ans+=max(abs(deq.at(0)-left),abs(deq.at(n-2)-left));
    cout<<ans<<endl;
    return 0;
}
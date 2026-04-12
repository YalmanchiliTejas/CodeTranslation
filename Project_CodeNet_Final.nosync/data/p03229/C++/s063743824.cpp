#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    ll n;cin>>n;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    sort(a.begin(),a.end());
    int l=1,r=n-1;
    ll left=a[0],right=a[0];
    ll res=0,res2=0;
    while(true){
        res+=abs(left-a[r]);
        left=a[r];
        if(l==r)break;
        r--;
        res+=abs(right-a[r]);
        right=a[r];
        if(l==r)break;
        r--;
        res+=abs(left-a[l]);
        left=a[l];
        if(l==r)break;
        l++;
        res+=abs(right-a[l]);
        right=a[l];
        if(l==r)break;
        l++;
    }
    reverse(a.begin(),a.end());
    l=1,r=n-1;
    left=a[0],right=a[0];
    while(true){
        res2+=abs(left-a[r]);
        left=a[r];
        if(l==r)break;
        r--;
        res2+=abs(right-a[r]);
        right=a[r];
        if(l==r)break;
        r--;
        res2+=abs(left-a[l]);
        left=a[l];
        if(l==r)break;
        l++;
        res2+=abs(right-a[l]);
        right=a[l];
        if(l==r)break;
        l++;
    }
    chmax(res,res2);
    cout<<res<<endl;
}
#include <iostream>
#include <bits/stdc++.h>

#define rep(i,z) for(int i = 0; i<(int)(z); i++)
#define rep1(i,z) for(int i = 1; i<=(int)(z); i++)
 
using namespace std;

typedef long long ll;
const ll mod=1e9+7;
 
using pear = pair<int,int>;
 
int main(){
    int n; cin >>n;
    vector<int> a(n);
    rep(i,n) cin>>a[i];
    deque<int> d;
    rep(i,n){
        int p = lower_bound(d.begin(),d.end(),a[i])-d.begin();
        if(p==0){
            d.push_front(a[i]);
        }else d[p-1] = a[i];
    }
    int ans = d.size();
    cout <<ans<<endl;
}
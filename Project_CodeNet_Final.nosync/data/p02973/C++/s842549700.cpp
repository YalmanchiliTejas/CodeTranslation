#include<bits/stdc++.h>
typedef long long ll;
#define INF 0x3f3f3f3f
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
using namespace std;
const int sz=1001, mod=1e9+7;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,i,x;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)cin>>a[i];
    map<int,int> mp;
    mp[a[0]]++;
    for(i=1;i<n;i++){
        auto it = mp.lower_bound(a[i]);
        if(it==mp.begin()){
            mp[a[i]]++;
        }else{
            --it;
            int x=it->first,y=it->second;
            mp.erase(it);
            if(y!=1) mp[x]=y-1;
            mp[a[i]]++;
        }
    }
    int res=0;
    for(auto x:mp)res+=x.yy;
    cout<<res;
}

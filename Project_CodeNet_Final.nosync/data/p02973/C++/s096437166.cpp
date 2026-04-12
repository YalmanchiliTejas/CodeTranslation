#include<bits/stdc++.h>
using namespace std;
#define arep(i,x,n) for(int i=int(x);i<(int)(n);i++)
#define rep(i,n) for(long long i = 0;i < n;++i)
#define pi 3.141592653589793
#define eps 0.00000001
#define INF 1e9+7  
using ll = long long; 
using P=pair<int,int>;
using lP=pair<ll,ll>;
using fP=pair<double,double>;


int main(){
    int n;
    cin>>n;
    multiset<ll>ans;
    vector<int>a(n);
    rep(i,n)cin>>a[i];
    ll c=1;
    for(int i=n-1;i>=0;--i){
        if(i==n-1){
            ans.insert(a[i]);
            i--;
        }
        auto it=ans.upper_bound(a[i]);
        if(it!=ans.end())ans.erase(it);
        else c++;
        ans.insert(a[i]);
    }
    cout<<c<<endl;

    return 0;
}
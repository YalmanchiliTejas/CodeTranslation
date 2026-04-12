#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100005],d[100005];
bool cmp(ll x,ll y){
    return x>y;
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        d[i]=-1;
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        *upper_bound(d+1,d+1+n,a[i],cmp)=a[i];
    }
    cout<<lower_bound(d+1,d+1+n,-1,cmp)-d-1<<endl;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define All(v) (v).begin(),(v).end()

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(All(a));
    int res=0;
    for(int i=0;i<(n-2)/2;i++)res-=2*a[i];
    for(int i=(n-2)/2+2;i<n;i++)res+=2*a[i];
    res-=a[(n-2)/2];
    n%2?res-=a[(n-2)/2+1]:res+=a[(n-2)/2+1];
    if(n%2){
        int p=0,m=0;
        for(int i=0;i<n/2;i++)m+=2*a[i];
        for(int i=n/2+2;i<n;i++)p+=2*a[i];
        p+=a[n/2]+a[n/2+1];
        res=max(res,p-m);
    }
    cout<<res<<endl;
}
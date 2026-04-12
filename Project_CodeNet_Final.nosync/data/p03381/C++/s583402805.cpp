#include <bits/stdc++.h>

using namespace std;

int INF=1e9;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    cin>>n;

    vector<long long> a(n),b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    
    sort(b.begin(),b.end());

    long long mid1=b[n/2-1],mid2=b[n/2];

    for(int i=0;i<n;i++){
        if(a[i]<=mid1)cout<<mid2<<endl;
        else if(mid2<=a[i])cout<<mid1<<endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define All(v) (v).begin(),(v).end()
int dy[8] = {-1,0,1,0,-1,1,1,-1};
int dx[8] = {0,1,0,-1,1,1,-1,-1};
const int mod = 1000000007;
const int inf = mod*mod;
const int d5 = 100100;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(All(a));
    int res=0,p,m;
    if(n%2==1){
        p=0;
        m=0;
        for(int i=0;i<n/2;i++)m+=2*a[i];
        for(int i=n/2+2;i<n;i++)p+=2*a[i];
        p+=a[n/2]+a[n/2+1];
        res=max(res,p-m);
        p=0;
        m=0;
        for(int i=0;i<(n-2)/2;i++)m+=2*a[i];
        for(int i=(n-2)/2+2;i<n;i++)p+=2*a[i];
        m+=a[(n-2)/2]+a[(n-2)/2+1];
        res=max(res,p-m);
    }else{
        p=0;
        m=0;
        for(int i=0;i<(n-2)/2;i++)m+=2*a[i];
        for(int i=(n-2)/2+2;i<n;i++)p+=2*a[i];
        p+=a[(n-2)/2+1];
        m+=a[(n-2)/2];
        res=max(res,p-m);
        p=0;
        m=0;
        for(int i=0;i<(n-2)/2;i++)m+=2*a[i];
        for(int i=(n-2)/2+2;i<n;i++)p+=2*a[i];
        p+=a[(n-2)/2+1];
        m+=a[(n-2)/2];
        res=max(res,p-m);
    }
    cout<<res<<endl;
}
#include<bits/stdc++.h>
using namespace std;
int n;
long long a[100010],ans;
int main(){
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    ans=a[n-1]+a[n-2]-(a[0]*2);
    for(int i=1;i<n/2;i++)ans+=a[n-i-2]+a[n-i]-(a[i]*2);
    if(n%2&&a[n/2+1]-a[n/2]>a[n/2]-a[n/2-1])ans+=a[n/2+1]+a[n/2-1]-(a[n/2]*2);
    cout<<ans<<endl;
}
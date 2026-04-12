#include<bits/stdc++.h>
using namespace std;
long long n,a[100000],c,mv=(1LL<<60);
int main(){
    cin>>n;for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++){if(a[i]>=(n+1)){c+=(a[i]-(n+1))/(n+1);a[i]%=(n+1);a[i]+=(n+1);}}
    for(int i=0;i<n;i++)a[i]+=c;
    sort(a,a+n);
    if(a[0]>=(n+1)){
        for(int i=0;i<n;i++)mv=min(mv,a[i]);c+=(mv-n)*n;
        for(int i=0;i<n;i++)a[i]=(a[i]-mv)+n;
    }
    while(true){
        sort(a,a+n);if(a[n-1]<n)break;
        for(int i=0;i<n-1;i++)a[i]++;
        a[n-1]-=n;c++;
    }
    cout<<c<<endl;
    return 0;
}
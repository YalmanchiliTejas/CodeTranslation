#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    long long a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    long long v[n];

    for(int i=0;(n-1)/2-i>=0;i+=2){
        v[(n-1)/2-i]=a[n-1-i];
    }
    for(int i=0;(n-1)/2-1-i>=0;i+=2){
        v[(n-1)/2-1-i]=a[1+i];
    }
    for(int i=0;(n-1)/2+1+i<n;i+=2){
        v[(n-1)/2+1+i]=a[i];
    }
    for(int i=0;(n-1)/2+2+i<n;i+=2){
        v[(n-1)/2+2+i]=a[n-2-i];
    }
    

    reverse(a,a+n);
    long long vv[n];

    for(int i=0;(n-1)/2-i>=0;i+=2){
        vv[(n-1)/2-i]=a[n-1-i];
    }
    for(int i=0;(n-1)/2-1-i>=0;i+=2){
        vv[(n-1)/2-1-i]=a[1+i];
    }
    for(int i=0;(n-1)/2+1+i<n;i+=2){
        vv[(n-1)/2+1+i]=a[i];
    }
    for(int i=0;(n-1)/2+2+i<n;i+=2){
        vv[(n-1)/2+2+i]=a[n-2-i];
    }


    long long ans=0,ans2=0;

    for(int i=1;i<n;i++) ans+=abs(v[i]-v[i-1]),ans2+=abs(vv[i]-vv[i-1]);



    cout<<max(ans,ans2)<<endl;

}
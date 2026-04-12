#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    int n;
    cin>>n;
    int a[n];
    //this questions statement is not clear
    int mx=-1e8+5,count=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        count+=(a[i]>=mx);
        mx=max(mx,a[i]);
    }
    cout<<count;
    
}
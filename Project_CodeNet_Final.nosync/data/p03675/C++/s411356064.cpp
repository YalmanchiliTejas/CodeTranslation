#include<bits/stdc++.h>
using namespace std;
int main(void){
    int n;
    cin>>n;
    
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    
    vector<int> v;
    
    for(int i=0;i<n;i++){
        if(i%2==0)v.push_back(a[i]);
        else v.insert(v.begin()+0,a[i]);
    }
    
    if(v.size()%2==1)reverse(v.begin(),v.end());
    
    for(int i=0;i<n;i++){
        if(i!=n-1)cout<<v[i]<<" ";
        else cout<<v[i]<<endl;
    }
    
    return 0;
}
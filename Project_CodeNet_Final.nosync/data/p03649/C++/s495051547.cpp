#include <bits/stdc++.h>
 
using namespace std;
 
const long long MOD=1e9+7;
const double PI=3.14159265359;



int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    long long  ans=0;
    
    int n;
    cin>>n;
    
    vector<long long> a(n);
    for(auto &i: a){
        cin>>i;
    }
    
    long long mel=*max_element(a.begin(),a.end());
    
    //long long stepsTot=0;
   
    while(mel>n-1){
        long long stepsTot=0;
        vector<long long> steps(n,0);
        for(int i=0; i<n; i++){
            if(a[i]>n-1){
                steps[i]=max((a[i]-n+1)/n,1ll);
                stepsTot+=steps[i];
            }
        }
        for(int i=0; i<n; i++){
            //cout<<steps[i]<<" ";
            a[i]=a[i]+stepsTot-steps[i]*(n+1);
        }
        ans+=stepsTot;
        mel=*max_element(a.begin(),a.end());
    }/*
    for(int i:a){
        cout<<i<<" ";
    }*/
    
    cout<<ans;
    
    
    
    
    
    return 0;
}
#include <iostream>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int ans=0;
    int high=0;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        high=max(a,high);
        if(a==high) ans++;
    }
    
    cout<<ans<<endl;
    
    return 0;
}
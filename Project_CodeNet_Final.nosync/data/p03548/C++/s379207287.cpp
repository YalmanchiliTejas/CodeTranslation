#include <iostream>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int main(){
    int x,y,z;
    cin>>x>>y>>z;
    int ans=0;
    
    for(int i=1;i<=x/y;i++){
        if(x>=i*y+(i+1)*z){
            ans=i;
        }
    }
    
    cout<<ans<<endl;
    
    return 0;
}
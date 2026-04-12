#include<bits/stdc++.h>
using namespace std;
int x,y,ans,n,h[1000];


int  main(){
    cin>>n;
    for(int i=0;i<n;i++)cin>>h[i];

    for(int i=0;i<n;i++){
        for(int u=0;u<i;u++){
            if(h[i]<h[u])break;
            if(i==u+1)ans++;
        }
    }
    cout<<ans+1<<endl;
}



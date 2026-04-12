#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x,y,z,sum=0,ans=0;
    cin>>x>>y>>z;
    for(int i=2;i<x;i++){
        sum = i*y+(i+1)*z;
        if(sum>x){
            ans=i-1;break;
        }
        else if(sum==x){
            ans= i;break;
        }
    }
    cout<<ans<<endl;
}

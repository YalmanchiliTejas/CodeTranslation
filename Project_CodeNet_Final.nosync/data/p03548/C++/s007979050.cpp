#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    int x,y,z;
    cin>>x>>y>>z;
    x=x-2*z;
    if(x<=0)cout<<0;
    else{
        int count=0;
        while(x>0){
            x=x-y;
            if(x>=0)count++;
            else break;
            x-=z;
        }
        cout<<count;
    }
}

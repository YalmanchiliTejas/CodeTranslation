#include<bits/stdc++.h>
using namespace std;
int main(){
    long long a,b,c,d=0,e=0,f=2,g=0,h[300001],i,j,k=0,l=0,r=0,p[300001],n[101],m,q,u,v,w,y,z;
    string s,t,x;
    cin>>s;
    for(i=0;i<s.size();i++){
        if(s[i]=='A'){
            d=1;
        }
        else{
            e=1;
        }
    }
    if(d==1&&e==1){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }
}
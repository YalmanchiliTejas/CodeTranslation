#include <bits/stdc++.h>
#define lol long long
using namespace std;
int main(){
    int a,b,c,ans,co=0;
    string s,t;
    cin>>a>>b>>c;
    ans=c;
    b+=c;
    while(ans<a){
        if(ans+b>a) break;
        else{
            ans+=b;
            co++;
        }
    }
    cout<<co<<"\n";
    return(0);
}
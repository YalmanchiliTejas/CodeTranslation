#include<bits/stdc++.h>
using namespace std;
int a,b,c,ans;
int main(){
    cin>>a>>b>>c;
    ans=a*100+b*10+c;
    if(ans%4 == 0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
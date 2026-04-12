#include<bits/stdc++.h>
using namespace std;
int r,g,b,t;
int main(){
    cin>>r>>g>>b;
    t=r*100+g*10+b;
    if(t%4==0)  cout<<"YES"<<endl;
    else        cout<<"NO\n";
    return 0;
}
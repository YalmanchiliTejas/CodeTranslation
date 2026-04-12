#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;

int main() {
    string s;
    string a,b,c;
    cin>>a>>b>>c;
    s=a+b+c;

    if(stoi(s)%4==0)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    
   
    
    return 0;
    }
    
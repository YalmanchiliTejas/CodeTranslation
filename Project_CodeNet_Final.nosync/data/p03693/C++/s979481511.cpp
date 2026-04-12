#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep2(i,a,b) for (int i = (a); i < (b); ++i)


int main(){
    string s;
    rep(i,3) cin>>s[i];

    int a = stoi(s);

    if(a%4==0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}

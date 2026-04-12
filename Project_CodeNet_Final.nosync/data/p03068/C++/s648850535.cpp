#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;

int main(){
    ll a,b,c,d,e,k,l,m,n,o=0,p,q,x,y,z,max1=0,ans;
    string s,t,u;
    cin>>n>>s>>k;
    for (ll i=0; i<n; i++) {
        if (s[i]!=s[k-1]) {
            s[i]='*';
        }
    }
    cout<<s<<endl;
}

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
using ll = long long;

int main(){
    ll b,c,d,e,k,l,m,n,o=0,p,q,x,y,z,max1=0,ans;
    string s,t,u;
    
    cin>>n;
    ll a[n];
    for (ll i=0; i<n; i++) {
        cin>>a[i];
        if(max1<=a[i]){
            o++;
            max1=a[i];
        }
    }
    cout<<o<<endl;
}


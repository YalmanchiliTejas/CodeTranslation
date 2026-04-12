#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
using ll = long long;

int main(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<ll> b = a;
    sort(a.begin(),a.end());
    ll x = a[n/2 - 1];
    ll y = a[n/2];
    for(int i=0;i<n;i++){
        if(b[i] <=x){
            cout<<y<<endl;
        }
        else{
            cout<<x<<endl;
        }
    }
    return 0;
}

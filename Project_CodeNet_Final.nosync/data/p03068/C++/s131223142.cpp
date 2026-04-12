#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll min(ll a,ll b){
    if(a<b)return a;
    else return b;
}
ll max(ll a,ll b){
    if(a>b)return a;
    else return b;
}

int main() {
    ll n,k;
    string s;
    cin>>n>>s>>k;
    for(ll i=0;i<s.size();i++){
        if(s[i]!=s[k-1]){
            s[i]='*';
        }
    }
    cout<<s<<endl;
    return 0;
}

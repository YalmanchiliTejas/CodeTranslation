#include <bits/stdc++.h>
using namespace std;
int n;
const long long D=1e9+7;
long long gcd(long long x,long long y){
    if(y==0)return x;
    return gcd(y,x%y);
}
long long pow2(long long x,long long y){
    if(y%2==0)return 1;
    long long ret=pow2(x,y/2);
    return ret*ret%D*(y%2==0 ? 1: x)%D;
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    string s;
    cin>>s;
    if(s[0]!=s[1] || s[1]!=s[2]){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }

    return 0;
}

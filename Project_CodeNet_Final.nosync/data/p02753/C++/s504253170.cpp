#include <bits/stdc++.h>
#include <stdlib.h>
#include <string>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001
#define mod 1000000007
#define pi 3.141592653589793
ll gcd(ll a,ll b){
    if(b>a) swap(a,b);
    ll r=a%b;
    while(r!=0){
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}

int main(){
    string s;
    cin >> s;
    if(s[0]==s[1]&&s[1]==s[2]) cout  << "No" << endl;
    else cout << "Yes" <<endl;
    return 0;
}
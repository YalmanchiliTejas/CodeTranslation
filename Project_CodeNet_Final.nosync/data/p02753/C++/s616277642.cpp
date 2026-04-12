#include <bits/stdc++.h>
using namespace std;
typedef  long long int ll;
string int2string(int x){
        stringstream ss;
        ss << x;
        string tmp;
        ss >> tmp;
        return tmp;
    }
int string2int(string s){
    stringstream ss;
    ss << s;
    int x;
    ss >> x;
    return x;
}
long long power(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
long long bigpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
ll gcd(ll a,ll b)
{
    if(b==0)
    return a;
    else return gcd(b,a%b);
}
ll lcm(ll a,ll b)
{
    ll r= a/gcd(a,b)*b;
    return r;
}
//***********************CODE*****************
int main(){
    
cin.tie(NULL);
cout.tie(NULL);
ios_base::sync_with_stdio(false);
string s;
cin>>s;
if(s[0]==s[1] && s[1]==s[2])
cout<<"No\n";
else cout<<"Yes\n";
    
    return 0;
}
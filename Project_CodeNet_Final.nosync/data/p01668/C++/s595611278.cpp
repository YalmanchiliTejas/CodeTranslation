#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int lli;
const lli mod = 1e9+7;

lli solve(string s, string pt){
    int n = s.length();
    int m = pt.length();
    vector<lli> csum_top(n+1, 0),csum_bottom(n+1, 0),pow10(n+1, 1);
    for(int i=0; i<n; i++){
        csum_top[i+1] = (csum_top[i]*10 +s[i]-'0') %mod;
        csum_bottom[i+1] = (csum_bottom[i] +(s[n-1-i]-'0')*pow10[i]) %mod;
        pow10[i+1] = pow10[i]*10 %mod;
    }
    if(pt == "0"){
        for(lli &a: csum_top){
            a = (a-1+mod) %mod;
        }
    }
    lli res = 0;
    for(int i=0; i+m-1<n; i++){
        string sub = s.substr(i, m);
        if(sub > pt){
            res += (csum_top[i]+1)*pow10[n-i-m] %mod;
        }else if(sub < pt){
            res += csum_top[i]*pow10[n-i-m] %mod;
        }else{
            res += csum_top[i]*pow10[n-i-m] %mod;
            res += csum_bottom[n-i-m]+1;
        }
        res %= mod;
    }
    return res;
}
lli numpt(string s, string pt){
    int n = s.length();
    int m = pt.length();
    lli res = 0;
    for(int i=0; i+m-1<n; i++){
        if(s.substr(i, m) == pt) res++;
    }
    return res;
}

int main(){
    string a,b,c;
    cin >> a >> b >> c;
    cout << (solve(b, c) -solve(a, c) +numpt(a, c) +mod) %mod << endl;
    return 0;
}


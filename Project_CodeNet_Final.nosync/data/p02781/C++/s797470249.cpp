#include <bits/stdc++.h>

long long com(int n, int k){
    if(k==1) return n;
    else if(k==2) return n*(n-1)/2;
    else return n*(n-1)*(n-2)/3/2;
}

long long pow_int(long long x, long long n){
    long long ret = 1;
    for (int i = 0; i < n; i++) ret *= x;
    return ret;    
}

long long calc_pattern(std::string &s, int digit, int n, int k, bool is_small){
    if(k==0) return 1;
    if(k>n) return 0;
    if(is_small) return pow_int(9, k) * com(n, k);
    long long ret = 0;
    if(s[digit]=='0'){
        return calc_pattern(s, digit+1, n-1, k, false);
    } else {
        ret += calc_pattern(s, digit+1, n-1, k-1, false);
        ret += calc_pattern(s, digit+1, n-1, k, true);
        ret += ( (int) s[digit] - '1' ) * calc_pattern(s, digit+1, n-1, k-1, true);
    }
    return ret;
}

int main(){
    using namespace std;
    string s; cin >> s;
    int k; cin >> k;
    int n = s.size();
    long long ans = 0;
    ans = calc_pattern(s, 0, n, k, false);
    cout << ans << endl;
}
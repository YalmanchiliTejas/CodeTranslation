#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

const int mod = 1000000;
long long dp[1010];
vector<string> bytes;

inline bool pref(const string &s) {
    return s[0] == '0' || s[1] == '1';
}

int c1(string s) {
    if(s[0] == '1') return 0;
    int ret = 1;
    for(int i=1; i<s.length(); ++i) {
        if(s[i] == 'x') ret *= 2;
    }

    return ret;
}

int c2(string s1,string s2) {
    if(s1[0] == '0' || s1[1] == '0' || s1[2] == '1') return 0;
    if(pref(s2)) return 0;
    int ret = 1;
    int one = 0,exe = 0;
    for(int i=3; i<=6; ++i) {
        if(s1[i] == '1') one++;
        if(s1[i] == 'x') exe++;
    }
    if(one == 0 && exe == 0) return 0;
    int p = 1;
    while(exe--) p *= 2;
    if(one == 0) p--;
    ret *= p;

    if(s1[7] == 'x') ret *= 2;
    for(int i=2; i<s2.length(); ++i) if(s2[i] == 'x') ret *= 2;
    return ret%mod;
}

int c3(string s1,string s2,string s3) {
    if(s1[0] == '0' || s1[1] == '0' || s1[2] == '0' || s1[3] == '1') return 0;
    if(pref(s2) || pref(s3)) return 0;
    int ret = 1;
    int one = 0,exe = 0;
    for(int i=4; i<s1.length(); ++i) {
        if(s1[i] == 'x') exe++;
        if(s1[i] == '1') one++;
    }
    if(s2[2] == 'x') exe++;
    if(s2[2] == '1') one++;
    if(one == 0 && exe == 0) return 0;
    int p = 1;
    while(exe--) p *= 2;
    if(one == 0) p--;
    ret *= p;

    ret %= mod;
    for(int i=3; i<s2.length(); ++i) if(s2[i] == 'x') ret *= 2;
    for(int i=2; i<s3.length(); ++i) if(s3[i] == 'x') ret *= 2;
    return ret%mod;
}

long long c4(string s1,string s2,string s3,string s4) {
    if(s1[0] == '0' || s1[1] == '0' || s1[2] == '0' || s1[3] == '0'
       || s1[4] == '1') return 0;
    if(pref(s2) || pref(s3) || pref(s4)) return 0;

    long long ret = 1;
    int one = 0,exe = 0;
    for(int i=5; i<s1.length(); ++i) {
        if(s1[i] == '1') one++;
        if(s1[i] == 'x') exe++;
    }
    if(s2[2] == '1') one++;
    if(s2[2] == 'x') exe++;
    if(s2[3] == '1') one++;
    if(s2[3] == 'x') exe++;
    if(one == 0 && exe == 0) return 0;
    int p = 1;
    while(exe--) p *= 2;
    if(one == 0) p--;
    ret *= p;

    for(int i=4; i<s2.length(); ++i) if(s2[i] == 'x') ret *= 2;
    ret %= mod;
    for(int i=2; i<8; ++i) {
        if(s3[i] == 'x') ret *= 2;
        if(s4[i] == 'x') ret *= 2;
        ret %= mod;
    }
    return ret%mod;
}

int main() {
    int n;
    string s;
    while(cin>>n, n) {
        bytes.clear();
        memset(dp, 0, sizeof(dp));
        for(int i=0; i<n; ++i) {
            cin>>s;
            bytes.push_back(s);
        }

        for(int i=0; i<n; ++i) {
            if(i == 0) {
                dp[i] = c1(bytes[0]);
            }else if(i == 1) {
                dp[1] = dp[0] * c1(bytes[1]);
                dp[1] %= mod;
                dp[1] += c2(bytes[0], bytes[1]);
            }else if(i == 2) {
                dp[2] = dp[1] * c1(bytes[2]);
                dp[2] %= mod;
                dp[2] += dp[0] * c2(bytes[1], bytes[2]);
                dp[2] %= mod;
                dp[2] += c3(bytes[0],bytes[1],bytes[2]);
            }else if(i == 3) {
                dp[3] = dp[2] * c1(bytes[3]);
                dp[3] %= mod;
                dp[3] += dp[1] * c2(bytes[2], bytes[3]);
                dp[3] %= mod;
                dp[3] += dp[0] * c3(bytes[1], bytes[2], bytes[3]);
                dp[3] %= mod;
                dp[3] += c4(bytes[0], bytes[1], bytes[2], bytes[3]);
            }else{
                dp[i] = dp[i-1] * c1(bytes[i]);
                dp[i] += dp[i-2] * c2(bytes[i-1], bytes[i]);
                dp[i] += dp[i-3] * c3(bytes[i-2], bytes[i-1], bytes[i]);
                dp[i] += dp[i-4] * c4(bytes[i-3], bytes[i-2], bytes[i-1], bytes[i]);
            }
            dp[i] %= mod;
            //cout<<i<<" "<<dp[i]<<endl;
        }
        cout<<dp[n-1]<<endl;
    }

    // cout<<c1("xxxxxxxx")<<endl;
    // cout<<c2("xxxxxxxx","xxxxxxxx")<<endl;
    // cout<<c3("xxxxxxxx","xxxxxxxx","xxxxxxxx")<<endl;
    // cout<<c4("xxxxxxxx","xxxxxxxx","xxxxxxxx","xxxxxxxx")<<endl;
}
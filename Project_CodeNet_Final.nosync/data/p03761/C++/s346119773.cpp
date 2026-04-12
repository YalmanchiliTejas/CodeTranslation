#include <bits/stdc++.h>
using namespace std;
typedef long long  ll ;

long long gcd(long long aaa,long long bbb) {
    if(bbb==0) {
        return aaa;
    }
    return gcd(bbb,aaa%bbb);
}

int main (){

    int n;
    cin >> n;
    string S[n],tmp="abcdefghijklmnopqrstuvwxyz";
    map<char,int>m;
    map<char,int>ans;
    for(int i = 0; i < n; i++) {
        cin >> S[i];
        for(int j = 0; j < S[i].size(); j++) {
            m[S[i][j]]++;
        }
        if(i >= 1) {
            for(int j = 0; j < 26; j++) {
                ans[tmp[j]] = min(ans[tmp[j]],m[tmp[j]]);
                m[tmp[j]] = 0;
            }
        }else {
            for(int j = 0; j < 26; j++) {
                ans[tmp[j]] = m[tmp[j]];
                m[tmp[j]] = 0;
            }
        }
    }

    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < ans[tmp[i]]; j++) {
            cout << tmp[i];
        }
    }
    cout << endl;
    return 0;
}

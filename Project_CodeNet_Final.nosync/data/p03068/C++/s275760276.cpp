#include <bits/stdc++.h>    
using namespace std;

#define CIN2(a,b) long long a,b;cin >> a >> b;
#define CIN3(a,b,c) long long a,b,c;cin >> a >> b >> c;
#define rep(i,n) for(int i=0,i##_len=(n); i<i##_len; ++i)

int main(){
    int n;cin >> n;
    string s;cin >> s;
    int k;cin >> k;
    
    rep(i,n){
        s[i] = (s[i]==s[k-1])?s[i]:'*';
    }
    cout << s << endl;
}

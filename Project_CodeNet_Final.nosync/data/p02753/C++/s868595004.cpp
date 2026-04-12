#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    string s;
    cin >> s;
    ll c = 0;
    rep(i, 0, 3){
        if(s[i] == 'A') c++;
    }
    if(c == 0 || c == 3) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}
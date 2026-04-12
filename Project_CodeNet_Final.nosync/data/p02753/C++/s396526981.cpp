#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    string S;
    cin >> S;
    ll a = 0, b = 0;
    rep(i, 0, 3){
        if(S[i] == 'A') a++;
        else b++;
    }
    if(a == 0 || b == 0) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}
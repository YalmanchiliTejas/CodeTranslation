#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    char S[3];
    rep(i, 3) cin >> S[i];

    if (( (S[0] == 'A')  && (S[1] == 'A')  && (S[2] == 'A') )||( (S[0] == 'B')  && (S[1] == 'B')  && (S[2] == 'B') )) cout << "No" << endl;
    else cout << "Yes" << endl;

    return 0;
}
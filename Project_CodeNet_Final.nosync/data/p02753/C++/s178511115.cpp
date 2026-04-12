#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;
typedef long long ll;

int main(){
    char S[3]; 
    rep(i,3) cin >> S[i];
    if (S[0]==S[1] && S[1]==S[2]) cout << "No";
    else cout << "Yes";
}
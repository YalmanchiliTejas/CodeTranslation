#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < (n); ++i)
typedef long long ll;
using namespace std;

int main(){
    string s; cin >> s;
    string a(3,'A');
    string b(3,'B');
    if(s == a || s == b) cout << "No" << endl;
    else cout << "Yes" << endl;
}
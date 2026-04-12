#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;

int main(){
    string s;
    cin >> s;
    if(s.at(0) == s.at(1) && s.at(1) == s.at(2) && s.at(0) == s.at(2)) cout << "No" << endl;
    else cout << "Yes" << endl;
}
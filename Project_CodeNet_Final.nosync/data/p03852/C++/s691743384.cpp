#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define repb(i, a, b) for(int i = a; i >= b; i--)
#define all(a) a.begin(), a.end()
#define int long long
using namespace std;
typedef pair<int, int> P;

signed main(){
    string c;
    cin >> c;
    string s = "aiueo";
    if(s.find(c) != string::npos) cout << "vowel" << endl;
    else cout << "consonant" << endl;
}
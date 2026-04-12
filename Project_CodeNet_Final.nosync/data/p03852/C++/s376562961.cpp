#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main(){
    char c; cin >> c;
    if(c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') cout << "vowel" << endl;
    else cout << "consonant" << endl;
}
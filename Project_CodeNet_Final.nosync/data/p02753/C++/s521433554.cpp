#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<class T,class U> using P = pair<T,U>;
template<class T> using vec = vector<T>;
template<class T> using vvec = vector<vec<T>>;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
 
int main(){
    string s;
    cin >> s;
    if (s[0]==s[1] && s[0]==s[2]) cout << "No" << endl;
    else cout << "Yes" << endl;
}
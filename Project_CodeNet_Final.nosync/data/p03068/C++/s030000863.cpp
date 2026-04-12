#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;
template<typename T>
void print(T x) {
    cout << x << endl;
}
int main(void) {
    int n; cin >> n;
    string s; cin >> s;
    int k; cin >> k; k--;
    char x = s[k];
    rep(i, s.size()) {
        if(s[i]!=x) s[i] ='*';
    }
    print(s);
}

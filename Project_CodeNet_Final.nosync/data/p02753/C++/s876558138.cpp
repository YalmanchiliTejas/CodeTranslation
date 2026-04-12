#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(int)(n); ++i)

int main(){
    string s;
    cin >> s;
    sort(s.begin(),s.end());
    rep(i,2){
        if (s[i] != s[i+1]){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
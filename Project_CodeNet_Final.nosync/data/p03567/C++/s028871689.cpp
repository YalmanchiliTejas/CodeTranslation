/*
      author : nishi5451
      created: 12.08.2020 10:57:08
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    string s;
    cin >> s;
    rep(i,s.size()-1){
        if(s[i]=='A' && s[i+1]=='C'){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
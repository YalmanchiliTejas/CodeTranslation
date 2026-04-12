/*
      author : nishi5451
      created: 11.08.2020 22:49:25
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    string s;
    cin >> s;
    if(s[0]==s[1] && s[1]==s[2]) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}
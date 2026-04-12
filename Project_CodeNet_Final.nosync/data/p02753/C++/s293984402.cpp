#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    string ans;
    if (s[0] == s[1] and s[1] == s[2]){
        ans = "No";
    }
    else{
        ans = "Yes";
    }

    cout << ans << endl;
}
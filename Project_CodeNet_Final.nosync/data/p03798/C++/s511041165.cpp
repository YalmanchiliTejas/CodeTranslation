#include<bits/stdc++.h>
using namespace std;

bool check(int n, string &s, string &ans){
    for (int i = 0; i < s.size(); i++){
        if (s[i] == 'o'){
            if (ans[i+1] == 'S') ans += ans[i];
            else {
                if (ans[i] == 'S') ans += 'W';
                else ans += 'S';
            }
        }
        else {
            if (ans[i+1] == 'W') ans += ans[i];
            else {
                if (ans[i] == 'S') ans += 'W';
                else ans += 'S';
            }
        }
    }
    if (ans[n] == ans[0] && ans[n+1] == ans[1]) cout << ans.substr(1, n) << endl;
    return (ans[n] == ans[0] && ans[n+1] == ans[1]);
}

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    string one = "SS";
    string two = "WW";
    string three = "SW";
    string four = "WS";
    if (check(n, s, one));
    else if (check(n, s, two));
    else if (check(n, s, three));
    else if (check(n, s, four));
    else cout << - 1 << endl;
}
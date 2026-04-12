#include<bits/stdc++.h>
 
using namespace std;

void solve(int TestCase) {
    string s;
    cin >> s;
    if(s[0] == s[1] && s[1] == s[2])
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t = 1;
    //cin >> t;
    for(auto i = 1; i <= t; ++i) {
    //    cout << "Case #"<< i << ": ";
        solve(i);
    }
}
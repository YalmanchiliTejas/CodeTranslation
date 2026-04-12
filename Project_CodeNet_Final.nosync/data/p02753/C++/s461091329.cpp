#include <iostream>
#include <string>
using namespace std;



void solve(){
    string s;
    cin >> s;
    if (s[0] != s[1] || s[0] != s[2] || s[1] != s[2])
        puts("Yes");
    else
        puts("No");
}

int main(){
    solve();
    return 0;
}
/*|In The Name Of Allah|*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;

int main(){
    string s;
    cin >> s;
    sort(s.begin() , s.end());
    if(s[0] != s[1] || s[1] != s[2]){
        puts("Yes");
    } else {
        puts("No");
    }
}

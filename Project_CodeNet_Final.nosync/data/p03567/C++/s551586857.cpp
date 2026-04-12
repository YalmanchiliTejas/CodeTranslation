#include<bits/stdc++.h>
using namespace std;
int main(void) {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    string str;
    while(cin >> str){
        if(str.find("AC") == string::npos) puts("No");
        else puts("Yes");
    }
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    char c ;
    cin >> c ;
    bool flag = 0 ;
    string str = "aiueo";
    rep(i,5){
        if(c == str.at(i)){
            flag = 1 ;
            break;
        }
    }
    if(flag) cout << "vowel" << endl;
    else cout << "consonant" << endl;
}
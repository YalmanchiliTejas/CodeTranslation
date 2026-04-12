#include<bits/stdc++.h>
using namespace std;
using lint = long long int;
 lint digit(lint);

int main(){

    string s;
    cin >> s;

    if(s[0] == s[1] && s[1] == s[2])cout << "No" << endl;
    else cout << "Yes" << endl;

}
lint digit(lint num){
    lint dig = 0;
    while(num){
        num /= 10;
        ++dig;
    }
    return dig;
}
#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    int a;
    int b;
    cin >> s;
    string result = "No";
    if(s[0] == s[2] || s[0] == s[1] || s[1] == s[2]){
        result = "Yes";
    }
    if(s[0] == s[1] && s[1] == s[2] && s[0] == s[2]){
        result = "No";
    }
    cout << result << endl;
}
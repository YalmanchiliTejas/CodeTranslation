#include <iostream>
#include <string>

int main() {
    using namespace std;
    string s;
    cin >> s;
    if((s[0] == s[1]) and (s[1] == s[2])){
        cout << "No";
    }else{
        cout << "Yes";
    }
}
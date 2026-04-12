#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;
    auto a = s[0];
    if(s[1] == a && s[2] == a)
        cout << "No" << endl;
    else
    {
        cout << "Yes" << endl;
    }
    return 0;
}
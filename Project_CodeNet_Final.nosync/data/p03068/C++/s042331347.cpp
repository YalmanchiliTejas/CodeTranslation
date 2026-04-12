#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int a, b;
    char c1;
    string s;
    cin>> a;
    cin>> s;
    cin >> b;
    c1 = s[b-1];
    for (int i = 0; i< s.length(); i++){
        if(s[i] ==c1 ){
            cout << s[i];
        }
        else {
            cout << "*";
        }
    }
    return 0;
}
#include <iostream>
using namespace std;

char c, cp;
bool f;

int main(){
    f = true;
    for (int i = 0; i < 3; ++i){
        cin >> c;
        if (i > 0){
            f &= (c == cp);
        }
        cp = c;
    }
    cout << (f ? "No" : "Yes");
}
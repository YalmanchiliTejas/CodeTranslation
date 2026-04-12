#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int main(void){
    int n,k;
    string s;

    cin >> n;
    cin >> s;
    cin >> k;

    for (auto& c : s) {
        if (c != s[k-1]) c = '*';
    }
    cout << s << endl;

    return 0;
}
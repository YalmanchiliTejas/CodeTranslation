#include <cstdio>
#include <iostream>
using namespace std;



int main(){
    string in;
    getline(cin, in);

    if(in == "AAA" || in == "BBB") {
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }

    return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    string S;

    cin >> S;

    if(S == "AAA" | S == "BBB")
    {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}
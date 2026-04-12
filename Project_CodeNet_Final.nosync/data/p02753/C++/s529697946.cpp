#include <iostream>

using namespace std;

int main(){
    string s;
    cin >> s;
    int sum=0;
    for (int i = 0; i < 3; ++i) {
        if(s[i] == 'A') sum++;
    }

    cout << ((sum == 3 || sum==0) ? "No" : "Yes") << endl;

    return 0;
}
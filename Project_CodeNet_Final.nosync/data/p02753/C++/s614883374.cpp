#include <iostream>
using namespace std;

int main () {
    char  S[3];
    cin >> S;
    bool ab[2] = {false, false};
    for(int i = 0; i < 3; i++) {
        if (S[i] == 'A') ab[0] = true;
        else ab[1] = true;
    }

    cout << ((ab[0] && ab[1]) ? "Yes" : "No") << endl;
    return 0;
}


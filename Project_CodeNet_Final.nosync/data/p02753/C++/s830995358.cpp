#include <iostream>

using namespace std;

int main() {

    bool isA = false;
    bool isB = false;
    for(int i = 0; i < 3; ++i) {
        char ch;
        cin >> ch;

        if(ch == 'A')
            isA = true;
        if(ch == 'B')
            isB = true;

    }

    if(isA && isB)
        cout << "Yes";
    else
    {
        cout << "No";
    }
    
    cout << endl;

    return 0;

}
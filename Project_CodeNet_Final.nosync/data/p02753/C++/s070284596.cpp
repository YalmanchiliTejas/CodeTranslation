#include <iostream>
#include <string>

using namespace std;

int
main()
{
    string s;
    cin >> s;

    if(s.length() > 3) {
        return -1;
    }

    if(s == "AAA" || s == "BBB"){
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }

    return 0;
}
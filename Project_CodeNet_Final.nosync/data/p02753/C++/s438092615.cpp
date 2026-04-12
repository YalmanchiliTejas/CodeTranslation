#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char    s[4];

    cin >> s;

    if (strcmp(s, "AAA") == 0 || strcmp(s, "BBB") == 0){
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
    return 0;
}
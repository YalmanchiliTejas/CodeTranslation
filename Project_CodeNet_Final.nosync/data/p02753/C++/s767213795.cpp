#include <iostream>
using namespace std;

int main()
{
    string s;
    int a[2] = {0};
    cin >> s;
    for (int i = 0; i < s.length(); i++){
        if (s[i] == 'A') a[0]++;
        if (s[i] == 'B') a[1]++;
    }
    if (a[0] && a[1]) cout << "Yes";
    else cout << "No";
    return 0;
}
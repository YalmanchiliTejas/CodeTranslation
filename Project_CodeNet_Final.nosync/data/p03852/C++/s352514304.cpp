#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    char a[1];
    cin >> a;

    if(a[0] == 'a' || a[0] == 'e' || a[0] == 'i' || a[0] == 'o' || a[0] == 'u')
        cout << "vowel\n";
    else
        cout << "consonant\n";

    return 0;
}

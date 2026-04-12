#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <iomanip>
#include <map>
#include <cstdlib>
#include <cctype>
#include <ctype.h>
#define ll long long
char toupper(char c);
char toupper(char c)
{
    return (c - 0x20);
}

using namespace std;
int main()
{
    int n;
    cin >> n;
    cout << n * 800 - n / 15 * 200 << endl;
    return 0;
}

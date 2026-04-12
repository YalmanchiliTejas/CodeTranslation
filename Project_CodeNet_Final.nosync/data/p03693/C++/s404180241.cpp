#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <iomanip>
#include <map>
#include <cstdlib>
using namespace std;
int main()
{
    string s;
    cin >> s[0] >> s[1] >> s[2];
    int a = atoi(s.c_str());
    cout << (a % 4 == 0 ? "YES" : "NO") << endl;
    return 0;
}
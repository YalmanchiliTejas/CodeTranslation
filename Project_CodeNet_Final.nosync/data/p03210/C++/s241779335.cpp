#include<iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int a;
    cin >> a;
    string ans = "NO";

    if(a == 3 || a == 5 || a == 7) ans = "YES";
    
    cout << ans << endl;

    return 0;
}

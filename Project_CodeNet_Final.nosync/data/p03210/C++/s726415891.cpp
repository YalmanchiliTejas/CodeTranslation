#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
#define REP(i,n) for(int i = 0; i < n; i++)

int main(void)
{
    int X;
    cin >> X;

    if(X == 3 || X == 5 || X == 7)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
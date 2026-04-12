#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <tuple>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int okane = 0;
    okane = n/15;
    cout << (800*n)-(okane*200) << endl;
}
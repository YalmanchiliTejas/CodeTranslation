#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int main()
{

    int r,b,g;

    cin >> r >> g >> b;

    int num = r * 100 + g * 10 + b;

    if(num % 4 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
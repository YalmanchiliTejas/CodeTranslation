#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if((a*100 + b*10 + c) % 4 == 0)
        cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}

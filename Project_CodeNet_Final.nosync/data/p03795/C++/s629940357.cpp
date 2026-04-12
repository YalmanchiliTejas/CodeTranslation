#include <bits/stdc++.h>
using namespace std;

int n, x, y;

int main()
{
cin >> n;
x = 800*n;
y = 200*(n/15);
cout << x-y << '\n';
return 0;
}
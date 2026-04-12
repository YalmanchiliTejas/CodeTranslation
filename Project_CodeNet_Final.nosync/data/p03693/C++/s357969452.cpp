#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int r,g,b;
    cin >> r >> g >> b;
    printf("%s",((10*g+b)%4==0?"YES":"NO"));
}
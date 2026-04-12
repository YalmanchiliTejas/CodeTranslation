#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int a , b, c;
    cin >> a >> b >> c;
    b*=10, b+=c;
    if(b%4)cout << "NO";
    else cout  << "YES";
}


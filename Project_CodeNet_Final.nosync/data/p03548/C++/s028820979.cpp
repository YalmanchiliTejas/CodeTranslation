#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long x, y, z, contador=1;
    cin >> x >> y >> z;
    while((contador+1)*(y+z)+z<=x)
    {
        contador++;
    }
    cout << contador << endl;
    return 0;
}
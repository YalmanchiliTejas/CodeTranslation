#include<bits/stdc++.h>
using namespace std;
char station[4];
int i;
int main()
{
    cin >> station;
    (station[0] != station[1] || station[0] != station[2]) ? cout << "Yes" << endl : cout << "No" << endl;
    return 0;
}
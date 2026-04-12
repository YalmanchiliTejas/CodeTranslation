#include <iostream>
#include <bitset>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
using namespace std;
using ll = long long int;
#define REP(i,n) for(int i=0;i<n;i++)

int main()
{
    int X, Y, Z;
    cin >> X >> Y >> Z;

    int ans = (int)(X-Z)/(Y+Z);

    cout << ans << endl;
}
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<cstddef>
#include<queue>
#include<math.h>
#include<iomanip>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    string ans = "No";
    if(n == m) ans = "Yes";
    cout << ans << endl;
    return 0;
}
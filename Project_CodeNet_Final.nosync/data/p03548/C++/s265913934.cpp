#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<vector>
using namespace std;

int main()
{
    int x, y, z;
    
    cin >> x >> y >> z;
    
    int ans = (x - z) / (y + z);
    
    cout << ans << endl;
    
    return 0;
}
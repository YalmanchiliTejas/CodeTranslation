#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
 
int main(void)
{
    int x, y, z, ans=0;
    cin >> x >> y >> z;

    for(int i = 1; i*y + z*(i+1) <= x;i++)
        ans = i;

    cout << ans << endl;  
}
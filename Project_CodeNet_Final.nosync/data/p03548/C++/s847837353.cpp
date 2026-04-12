#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>
#include<iomanip>
using namespace std;

int main(void)
{
    int x,y,z,total = 0,ans = 0;
    cin >> x >> y >> z;
    for(;;)
    {
        if(total + y + z * 2 <= x){total += y + z; ans++;}
        else{break;}
    }
    cout << ans << endl;
    return 0;
}
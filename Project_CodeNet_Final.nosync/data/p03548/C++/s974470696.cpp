#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
#define REP(i,n) for(int i = 0; i < n; i++)


int main(void)
{
    int X, Y, Z;
    cin >> X >> Y >> Z;

    int space = 0;
    int ans = 0;

    do
    {
        space += Y;
        if(space > (X-2*Z))
            break;
        else if(space == (X-2*Z)){
            ans++;
            break;
        }
        ans++;
        space += Z;
        
    }while(space <= (X-2*Z));

    cout << ans << endl;

    return 0;
}

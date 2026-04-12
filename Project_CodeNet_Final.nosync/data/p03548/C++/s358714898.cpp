#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <math.h>

using namespace std;

int main()
{
    int x, y, z;
    cin >> x >> y >> z;
    int sum=z;
    int ans=0;
    while(sum+y+z<=x){
        ans++;
        sum=sum+y+z;
    }
    cout << ans << endl;
    
    return 0;
}
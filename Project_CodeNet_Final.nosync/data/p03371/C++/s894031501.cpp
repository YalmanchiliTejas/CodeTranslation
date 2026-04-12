#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <set>
#include <map>
#include <iterator>
#include <stack>
#include <string.h>
#include <cstdlib>
#include <queue>
#include <list>
#include <string>

using namespace std;

int main()
{
    int a,b,c;
    int x,y;
    cin >> a >> b >> c >> x >> y;
    long long ans = a*x + b*y;
    
    for (int i = 2;i <= 2*max(x,y);i+=2){
        long long m;
        if (i/2 <= x && i/2 <= y){
            m = i*c + (x - i/2)*a + (y-i/2)*b;
        }
        else if (i/2 <= x && i/2 > y){
            m = i*c + (x-i/2)*a;
        }
        else if (i/2 > x && i/2 <= y){
            m = i*c + (y-i/2)*b;
        }
        else {
            m = i*c;
        }
        ans = min(ans,m);
    }
    
    cout << ans << endl;
}

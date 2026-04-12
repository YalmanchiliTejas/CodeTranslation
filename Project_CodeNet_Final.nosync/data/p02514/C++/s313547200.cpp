#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <climits>
#include <cfloat>
using namespace std;

class Date
{
public:
    int y, m, d;
    bool operator<(const Date a) const{
        return y < a.y || (y == a.y && m < a.m) || (y == a.y && m == a.m && d < a.d);
    }
};

int main()
{
    for(;;){
        int n;
        cin >> n;
        if(n == 0)
            return 0;

        vector<Date> a(n);
        for(int i=0; i<n; ++i)
            cin >> a[i].y >> a[i].m >> a[i].d;
        sort(a.begin(), a.end());

        for(int i=0; i<n; ++i)
            printf("%04d %02d %02d\n", a[i].y, a[i].m, a[i].d);
    }
}
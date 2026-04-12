#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
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

int main()
{
    for(;;){
        int n, a, b, c, x;
        cin >> n >> a >> b >> c >> x;
        if(n == 0)
            return 0;

        vector<int> y(n);
        for(int i=0; i<n; ++i)
            cin >> y[i];

        int k = 0;
        for(int i=0; i<=10000; ++i){
            if(x == y[k])
                ++ k;
            if(k == n){
                cout << i << endl;
                break;
            }else if(i == 10000){
                cout << -1 << endl;
            }

            x = (a * x + b) % c;
        }
    }
}
#define _USE_MATH_DEFINES
#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <complex>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <limits>
#include <climits>
#include <cfloat>
#include <functional>
#include <iterator>
using namespace std;

int main()
{
    int len;
    string s, t;
    cin >> len >> s >> t;

    string ans = "~";
    for(int i=0; i<2; ++i){
        int n = s.size();
        int m = t.size();
        int x = len / n * n;
        while((len - x) % m != 0)
            x -= n;

        string a;
        while(a.size() < x)
            a += s;
        while(a.size() < len)
            a += t;
        ans = min(ans, a);

        swap(s, t);
    }
    cout << ans << endl;

    return 0;
}

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <set>
#include <algorithm>
#include <math.h>
using namespace std;
using i64 = int64_t;
#define rep(i, n) for(int i=0;i<n;++i)
#define rep2(i, x, n) for(int i=x;i<n;++i)

int main()
{   
    int x,y,z;
    cin >> x >> y >> z;
    cout << (x-z)/(y+z) << endl;
    return 0;
}
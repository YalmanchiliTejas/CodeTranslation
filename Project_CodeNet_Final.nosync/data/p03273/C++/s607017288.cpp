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
#include <array>
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
#include <memory>
#include <regex>
using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;

    vector<string> s(h, string(w, ' '));
    vector<bool> a(h, false), b(w, false);
    for(int y=0; y<h; ++y){
        for(int x=0; x<w; ++x){
            cin >> s[y][x];
            if(s[y][x] == '#'){
                a[y] = true;
                b[x] = true;
            }
        }
    }
    
    for(int y=0; y<h; ++y){
        if(!a[y])
            continue;
        for(int x=0; x<w; ++x){
            if(b[x])
                cout << s[y][x];
        }
        cout << endl;
    }

    return 0;
}

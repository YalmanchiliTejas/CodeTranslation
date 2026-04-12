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

int main()
{
    int left[] = {1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1,1,1,0,1};

    for(;;){
        string s;
        cin >> s;
        if(s == "#")
            return 0;

        int n = s.size();
        int ret = 0;
        for(int i=1; i<n; ++i){
            if(left[s[i]-'a'] != left[s[i-1]-'a'])
                ++ ret;
        }
        cout << ret << endl;
    }
}
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
    for(;;){
        vector<int> a(5);
        for(int i=0; i<5; ++i){
            int b;
            cin >> a[i] >> b;
            a[i] += b;
            if(a[i] == 0)
                return 0;
        }

        int i = max_element(a.begin(), a.end()) - a.begin();
        cout << (char)(i + 'A') << ' ' << a[i] << endl;
    }
}
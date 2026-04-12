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
        int n;
        cin >> n;
        if(n == 0)
            return 0;

        bool isBlack;
        vector<int> index(1, 1);
        int a;
        cin >> a;
        isBlack = (a == 1);
        for(int i=2; i<=n; ++i){
            cin >> a;
            if(isBlack != (a == 1)){
                isBlack = !isBlack;
                if(i % 2 == 1)
                    index.push_back(i);
                else{
                    if(index.size() > 1)
                        index.pop_back();
                }
            }
        }

        int ret1 = 0;
        int ret2 = 0;
        index.push_back(n+1);
        for(unsigned i=0; i<index.size()-1; ++i){
            if(i % 2 == 0)
                ret1 += index[i+1] - index[i];
            else
                ret2 += index[i+1] - index[i];
        }
        if(isBlack ^ (index.size() % 2 == 0))
            cout << ret1 << endl;
        else
            cout << ret2 << endl;
    }
}
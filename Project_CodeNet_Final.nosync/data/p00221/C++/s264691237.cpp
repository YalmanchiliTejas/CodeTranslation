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
        int m, n;
        cin >> m >> n;
        if(m == 0)
            return 0;

        list<int> rest;
        for(int i=1; i<=m; ++i)
            rest.push_back(i);

        list<int>::iterator it = rest.begin();
        for(int i=1; i<=n; ++i){
            string s;
            cin >> s;
            bool ng = false;
            if(i % 3 == 0 && i % 5 == 0){
                if(s != "FizzBuzz")
                    ng = true;
            }else if(i % 3 == 0){
                if(s != "Fizz")
                    ng = true;
            }else if(i % 5 == 0){
                if(s != "Buzz")
                    ng = true;
            }else{
                ostringstream oss;
                oss << i;
                if(s != oss.str())
                    ng = true;
            }

            if(ng && rest.size() > 1)
                it = rest.erase(it);
            else
                ++ it;
            if(it == rest.end())
                it = rest.begin();
        }

        cout << (*rest.begin());
        for(it=++rest.begin(); it!=rest.end(); ++it)
            cout << ' ' << (*it);
        cout << endl;
    }
}
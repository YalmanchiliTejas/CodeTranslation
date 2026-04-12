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
    multimap<int, int> mm;
    for(;;){
        int a, b;
        char c;
        cin >> a >> c >> b;
        if(a == 0 && b == 0)
            break;
        mm.insert(make_pair(30-b, a));
    }

    for(;;){
        int a;
        if(!(cin >> a))
            return 0;

        int rank = 0;
        int score = -1;
        multimap<int, int>::iterator it;
        for(it = mm.begin(); ; ++it){
            if(it->first != score){
                score = it->first;
                ++ rank;
            }
            if(it->second == a){
                cout << rank << endl;
                break;
            }
        }
    }
}
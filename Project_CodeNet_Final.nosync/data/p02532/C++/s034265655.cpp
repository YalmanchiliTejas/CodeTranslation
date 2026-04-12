#include <cstdio>
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
    int n;
    cin >> n;
    vector<stack<char> > stk(n+1);

    for(;;){
        string ope;
        int i;
        cin >> ope >> i;
        if(ope == "quit")
            return 0;

        if(ope == "push"){
            char c;
            cin >> c;
            stk[i].push(c);
        }else if(ope == "move"){
            int j;
            cin >> j;
            stk[j].push(stk[i].top());
            stk[i].pop();
        }else{
            cout << stk[i].top() << endl;
            stk[i].pop();
        }
    }
}
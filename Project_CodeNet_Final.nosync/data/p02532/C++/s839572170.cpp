#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <ctype.h>
#include <algorithm>
#include <cmath>
#include <vector>

#define REP(i, n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()
#define square(x) (x) * (x)

const int INF = 1e9;

using namespace std;

int main() {
    string order, color;
    int num;
    ostringstream res;
    cin >> num;
    vector<stack<string> > m(num);
    while(1){
        cin >> order;
        if (order == "quit")
            break;
        if (order == "push"){
            cin >> num >> color;
            num--;
            m[num].push(color);
        }
        if (order == "pop"){
            cin >> num;
            num--;
            res << m[num].top() << endl;
            m[num].pop();
        }
        if (order == "move"){
            int fr, to;
            cin >> fr >> to;
            fr--;
            to--;
            color = m[fr].top();
            m[fr].pop();
            m[to].push(color);
        }
    }


    cout << res.str();
    return 0;
}
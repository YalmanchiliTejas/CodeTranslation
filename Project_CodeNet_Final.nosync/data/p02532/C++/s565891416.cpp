#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
typedef pair<int, int> pint;
#define MOD 1000000007 //10^9+7
#define INF 1000000000 //10^9

int main (int argc, const char * argv[])
{
    stack<char> yama[100];
    int n;
    cin>>n;
    string str;
    while (1) {
        int n,m;
        char b;
        cin>>str;
        if (str=="quit") break;
        else if (str=="push") {
            cin>>n>>b;
            yama[n-1].push(b);
        }else if(str=="move"){
            cin>>n>>m;
            yama[m-1].push(yama[n-1].top());
            yama[n-1].pop();
        }else if(str=="pop"){
            cin>>n;
            cout<<yama[n-1].top()<<endl;
            yama[n-1].pop();
        }
    }
    
    return 0;
}
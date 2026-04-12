#include <iostream>
#include <vector>
#include "unordered_map"
#include "map"
#include <cmath>
#include <climits>
#include "queue"
#include "tuple"
#include <algorithm>
#include <iomanip>
#include "sstream"
#include <math.h>

using ll=long long;
using ull=unsigned long long;
using ld=long double;
using namespace std;

//const double PI = M_PI;

template <typename T>
inline void printQueue(queue<T>&oq){queue<T>q(oq);int qCount=q.size();for(int i=0;i<qCount;++i){T qe=q.front();q.pop();
        cout<<qe;if(i!=qCount-1){cout << ", ";}q.push(qe);}cout << endl;}

template<typename T>
inline void PV(vector<T> v){int vc=v.size();for(int i=0;i<vc;++i){cout << v[i];if(i!=vc-1){cout<<", ";}}cout << endl;}

inline double round( double val )
{
    if( val < 0 ) return ceil(val - 0.5);
    return floor(val + 0.5);
}

int main() {
//    freopen("../input.txt","r",stdin);
//    freopen("../output.txt","w",stdout);
    ull r;
    cin >> r;
    ull g;
    cin >> g;
    ull b;
    cin >> b;
    int n = r * 100 + g * 10 + b;
    if(n % 4 == 0) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
}

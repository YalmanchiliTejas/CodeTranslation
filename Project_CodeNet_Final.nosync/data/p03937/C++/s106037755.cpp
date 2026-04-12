#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <numeric>
#include <complex>
#include <string>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <fstream>
#include <climits>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int, int> pnt;

#define FI(i,a) for (int i=0; i<(a); ++i)
#define FOR(i,s,e) for (int i=(s); i<(e); ++i)
#define MEMS(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
#define ALL(a) a.begin(),a.end()
#define V(t) vector < t >
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):(-(a)))

const double pi = 3.14159265358979323846264338327950288419716939937511;
const double eps = 1e-9;
using namespace std;

int main(){
    
//    freopen("elect.out", "w", stdout);
//    freopen("input.txt", "r", stdin);
    
    int rows, cols;
    cin >> rows >> cols;
    
    int visited_count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            char temp;
            cin >> temp;
            if (temp == '#') visited_count++;
        }
    }

    bool possible = (visited_count == rows + cols - 1) ? true : false;
    
    if (possible) {
        cout << "Possible" << endl;
    } else {
        cout << "Impossible" << endl;
    }
        
}
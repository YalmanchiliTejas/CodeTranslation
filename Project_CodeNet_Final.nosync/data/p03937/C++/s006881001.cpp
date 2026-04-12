#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <climits>
#include <map>
#include <set>
const int mod = 1e9 + 7;
const int inf = 1 << 20;
const long long INF = 1LL << 60;
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
using namespace std;

int main()
{
    int h,w;
    cin >> h >> w;
    int cnt = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            char c;
            cin >> c;
            if(c == '#') cnt++;
        }
    }
    if(cnt == h + w -1) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
}
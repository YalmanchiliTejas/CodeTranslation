#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int,int> P;

const int INF = 1e9;
const int mod = 1e9+7;
const double EPS = 1e-10;
const double PI = acos(-1.0);

int main()
{
    int h,w;
    cin >> h >> w;
    char a[h][w];
    for(int i = 0; i < h; i++) for(int j = 0; j < w; j++) cin >> a[i][j];
    int cnt = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(a[i][j] == '#') cnt++;
        }
    }
    cout << (cnt != w+h-1 ? "Impossible" : "Possible") << endl;
    return 0;
}
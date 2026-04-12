#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <bitset>
#include <vector>
#include <queue>
#include <map>
#include <set>

#define i64 int64_t
#define ff(ii,nn,mm) for(int ii=nn;ii<mm;ii++)
#define ffrvs(ii,nn,mm) for(int ii=nn;ii>=mm;ii--)
#define srt(vvv) sort(vvv.begin(),vvv.end())
#define srtrvs(vvv) reverse(vvv.begin(),vvv.end())
#define Graph vector<vector<int>>
i64 inf = 1000000007;
i64 giant = 4000000000000000037;

using namespace std;

//メモリ置き場
int n, m;


//inputします
void input() {
    cin >> n >> m;
}

//ライブラリ置き場

//main
int main() {
    input();
    if (n == m) {
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;
    return 0;
}
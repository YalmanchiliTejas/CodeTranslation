#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <math.h>
#include <set>
#define ALL(obj) (obj).begin(),(obj).end()
#define RALL(obj) (obj).rbegin(),(obj).rend()
#define P pair<int, int>

#define MOD 1000000007
#define INF 2147483647
#define NINF (-2147483647-1)
#define LLINF 9223372036854775807
using ll = long long;
using namespace std; 

int main() {
    int N,M=0,ans=0;
    cin >> N;
    vector<int > H(N);
    for (int i = 0; i < N; i++)
    {
        cin >> H[i];
        if (M <= H[i]) {
            M = H[i];
            ans++;
        }
    }
    cout << ans << endl;
    getchar(); getchar();
    return 0;
}
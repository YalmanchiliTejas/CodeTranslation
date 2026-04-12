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
    int N, K;
    string S;
    cin >> N;
    cin >> S;
    cin >> K;
    char c = S[K-1];
    for (int i = 0; i < S.length(); i++)
    {
        if (c != S[i]) {
            S[i] = '*';
        }
    }
    cout << S << endl;
    getchar(); getchar();
    return 0;
}
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <list>
#include <queue>
#include <string>
#include <map>
using namespace std;
#define REP(i, a, n) for (int i = ((int)a); i < ((int)n); i++)
#define lli long long int

#define MAX 100000000
//#define DEBUG

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main()
{
#ifdef DEBUG
    cout << "DEBUG MODE" << endl;
#else
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
#endif
    int N;
    string S;
    int n;
    string out;
    cin >> N >> S >> n;
    for (int i = 0; i < N; i++)
    {
        if (S[i] == S[n-1])
        {
            out.push_back(S[n-1]);
        }
        else
        {
            out.push_back('*');
        }
    }
    cout << out << endl;
    return 0;
}
/* 注意すべき点
グローバル以外の配列は初期化すべし
*/
#include <algorithm>
#include <iostream> //入出力
#include <stdio.h>
#include <map>
#include <string>
#include <math.h>
#include <vector>
#include <cstdlib>
#include <queue>
#include <stack>
#include <list>
#include <iomanip> //小数点以下を表示させる(setprecision())

#define debug(x) cerr << x << " " \
                      << "(L:" << __LINE__ << ")" << '\n'
#define PRINT(V)                                   \
        {                                          \
                for (int i = 0; i < V.size(); i++) \
                {                                  \
                        cout << V[i] << " ";       \
                }                                  \
                cout << endl;                      \
        }

typedef long long ll; //64bit型
using namespace std;
const ll INF = 1LL << 20;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main()
{
        int N;
        cin >> N;
        vector<int> vec(N + 1);
        for (int i = 0; i < N; i++)
        {
                cin >> vec[i];
        }

        int a = 0, cnt = 0;

        for (int i = 0; i < N; i++)
        {
                a = max(a, vec[i]);
                if (a == vec[i])
                {
                        cnt++;
                }
        }
        cout << cnt << endl;

        return 0;
}
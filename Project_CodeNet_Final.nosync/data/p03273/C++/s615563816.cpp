#include <algorithm>
#include <iostream> //入出力
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <math.h> //算術演算子
#include <vector>
#include <cstdlib>
#include <queue>
#include <stack>
#include <list>
#include <iomanip> //小数点以下を表示させる(setprecision())
//#include <bits/stdc++.h>
using namespace std;
typedef long long ll; //64bit型

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

int gcd(int a, int b)
{
        return b ? gcd(b, a % b) : a;
}
int H, W;
string bo[110];
bool gx[110], gy[110];

int main()
{
        //input->compute->output//

        cin >> H >> W;

        for (int i = 0; i < H; i++)
        {

                cin >> bo[i];
        }

        for (int i = 0; i < H; i++)
        {
                for (int j = 0; j < W; j++)
                {
                        if (bo[i][j] == '#')
                        {
                                gx[i] = true;
                                gy[j] = true;
                        }
                }
        }

        for (int i = 0; i < H; i++)
        {
                if (gx[i])
                {
                        for (int j = 0; j < W; j++)
                        {
                                if (gy[j])
                                {

                                        cout << bo[i][j];
                                }
                        }
                        cout << endl;
                }
        }

        return 0;
}

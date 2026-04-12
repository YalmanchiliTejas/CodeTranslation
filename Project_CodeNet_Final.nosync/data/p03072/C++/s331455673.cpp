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
int main()
{
        //input->compute->output//
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++)
        {
                cin >> A[i];
        }

        int ans = 0;
        int height = 0;

        for (int i = 0; i < N; i++)
        {
                height = max(height, A[i]);
                if (height == A[i])
                {
                        ans++;
                }
        }

        cout << ans << endl;
        return 0;
}

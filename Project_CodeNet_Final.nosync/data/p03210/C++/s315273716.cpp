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

        if (N==7||N==5||N==3)
        {
                cout << "YES" << endl;
        } else{
                cout << "NO" << endl;
        }

        return 0;
}

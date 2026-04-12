#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <memory.h>
#include <ctime>
#include <bitset>
#include <vector>
#include <string>
#include <queue>

using namespace std;

void solution() {
    string s;
    cin >> s;
    if (s[0] == s[1] && s[1] == s[2]) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
}

/*-------------------*/

int main()
{
#ifdef Files
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    /*Test*/
    //freopen("input.txt", "w", stdout);

    double OcZ2X = clock();
#else
    //freopen("joke.in", "r", stdin);
    //freopen("joke.out", "w", stdout);
#endif

/*
　　     　 　          ∧_,,∧　　　
    　            ♪　  (・ω・)　♪
               ＿＿＿＿○＿＿つヾ＿＿＿＿＿
             /δ⊆・⊇ 。/†: :† /δ ⊆・⊇｡ /|
            |￣￣￣￣￣￣￣￣￣￣￣￣￣ | |
            |　　　*/solution();/* 　　| |
            |　　　　　　　　　　　　　 |
*/

#ifdef Time
    double P2HxQ = clock();
    printf("\n*** Total time = %.3f sec ***\n", (P2HxQ - OcZ2X) / CLOCKS_PER_SEC);
#endif
}
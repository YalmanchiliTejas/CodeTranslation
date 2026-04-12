#include <sstream>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>

typedef long long ll;

#define REP(i,n) for(int i=0;i<n;++i)

using namespace std;

char check[4][100010];

int main()
{
    int N;
    string s;
    cin >> N >> s;

    check[0][0] = check[1][0] = 'S';    // s[0] が S の場合
    check[2][0] = check[3][0] = 'W';    // s[0] が W の場合
    if(s[0] == 'o')
    {
        check[0][1] = check[0][s.size()-1] = 'S';   // 両隣が S
        check[1][1] = check[1][s.size()-1] = 'W';   // 両隣が W
        check[2][1] = check[3][s.size()-1] = 'S';   // 2 は右が S 左が W
        check[3][1] = check[2][s.size()-1] = 'W';   // 3 は右が W 左が S
    } else {
        check[0][1] = check[1][s.size()-1] = 'S';   // 0 は右が S 左が W
        check[1][1] = check[0][s.size()-1] = 'W';   // 1 は右が W 左が S
        check[2][1] = check[2][s.size()-1] = 'S';   // 両隣が S
        check[3][1] = check[3][s.size()-1] = 'W';   // 両隣が W
    }
    int i;
    for(i=1; i<s.size()-2; ++i) {
        REP(j, 4) {
            if(s[i] == 'o') {
                if(check[j][i] == 'S')     { check[j][i+1] = check[j][i-1]; }
                else if(check[j][i] == 'W'){ check[j][i+1] = (check[j][i-1]=='S') ? 'W' : 'S'; }
            } else {
                if(check[j][i] == 'W')     { check[j][i+1] = check[j][i-1]; }
                else if(check[j][i] == 'S'){ check[j][i+1] = (check[j][i-1]=='S') ? 'W' : 'S'; }
            }
        }
    }
    int isExist = -1;
    REP(j,4) {
        if(s[i] == 'o') {
            if(check[j][i] == 'S' && check[j][i+1] == check[j][i-1])
            {
                if(s[i+1] == 'o') {
                    if(check[j][i+1] == 'S' && check[j][i] == check[j][0]) { isExist = j; break; }
                    else if(check[j][i+1] == 'W' && check[j][i] != check[j][0]) { isExist = j; break; }
                } else  {
                    if(check[j][i+1] == 'W' && check[j][i] == check[j][0]) { isExist = j; break; }
                    else if(check[j][i+1] == 'S' && check[j][i] != check[j][0]) { isExist = j; break; }
                }
            }
            else if(check[j][i] == 'W' && check[j][i+1] != check[j][i-1])
            {
                if(s[i+1] == 'o') {
                    if(check[j][i+1] == 'S' && check[j][i] == check[j][0]) { isExist = j; break; }
                    else if(check[j][i+1] == 'W' && check[j][i] != check[j][0]) { isExist = j; break; }
                } else  {
                    if(check[j][i+1] == 'W' && check[j][i] == check[j][0]) { isExist = j; break; }
                    else if(check[j][i+1] == 'S' && check[j][i] != check[j][0]) { isExist = j; break; }
                }
            }
        } else {
            if(check[j][i] == 'W' && check[j][i+1] == check[j][i-1])
            {
                if(s[i+1] == 'o') {
                    if(check[j][i+1] == 'S' && check[j][i] == check[j][0]) { isExist = j; break; }
                    else if(check[j][i+1] == 'W' && check[j][i] != check[j][0]) { isExist = j; break; }
                } else  {
                    if(check[j][i+1] == 'W' && check[j][i] == check[j][0]) { isExist = j; break; }
                    else if(check[j][i+1] == 'S' && check[j][i] != check[j][0]) { isExist = j; break; }
                }
            }
            else if(check[j][i] == 'S' && check[j][i+1] != check[j][i-1])
            {
                if(s[i+1] == 'o') {
                    if(check[j][i+1] == 'S' && check[j][i] == check[j][0]) { isExist = j; break; }
                    else if(check[j][i+1] == 'W' && check[j][i] != check[j][0]) { isExist = j; break; }
                } else  {
                    if(check[j][i+1] == 'W' && check[j][i] == check[j][0]) { isExist = j; break; }
                    else if(check[j][i+1] == 'S' && check[j][i] != check[j][0]) { isExist = j; break; }
                }
            }
        }
    }
    if(isExist < 0){ printf("-1\n"); return 0; }
    REP(j, s.size()) { printf("%c", check[isExist][j]); }
    printf("\n");

    return 0;
}

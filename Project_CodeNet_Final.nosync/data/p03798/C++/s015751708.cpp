#include <iostream>
#include <utility>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdint>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc,char** argv) {
    int n;
    string s;
    cin >> n >> s;
    string r[4];
    int res = -1;
    for(int i = 0;i < 4;i++) {
        if(i % 2) r[i].append("S");
        else r[i].append("W");
        if(i > 1) r[i].append("S");
        else r[i].append("W");
    }
    for(int i = 0;i < 4;i++) {
        for(int j = 2;j < n;j++) {
            bool sheep = true;
            if(r[i][j-2] == 'W') sheep = !sheep;
            if(s[j-1] == 'x') sheep = !sheep;
            if(r[i][j-1] == 'W') sheep = !sheep;
            if(sheep) r[i].append("S");
            else r[i].append("W");
        }
        bool ok = true;
        for(int j = 0;j < 2;j++) {
            bool sheep = true;
            if(r[i][n + (j-2)] == 'W') sheep = !sheep;
            if(s[(n + (j-1))%n] == 'x') sheep = !sheep;
            if(r[i][(n + (j-1))%n] == 'W') sheep = !sheep;
            if((sheep && r[i][j] =='W') || (!sheep && r[i][j] =='S')) ok = false;
        }
        if(ok) res = i;
    }
    if(res == -1) cout << -1 << endl;
    else cout << r[res] << endl;
    return 0;
}

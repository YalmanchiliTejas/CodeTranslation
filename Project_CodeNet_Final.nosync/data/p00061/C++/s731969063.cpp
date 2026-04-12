#include <iostream>
#include <complex>
#include <cmath>
#include <cstdio>
#include <string>
#include <sstream>
#include <map>

using namespace std;

int main() {
    map<int, int> solved;
    map<int, bool> rank;
    while(1) {
        int no, ac;
        scanf("%d,%d", &no, &ac);
        if (no == 0)break;
        solved[no] = ac;
        rank[ac] = true;
    }
    int no;
    while(scanf("%d", &no) != EOF) {
        int res = 1;
        for (int i = 30; i > solved[no]; i--) {
            if (rank[i])res++;
        }
        cout << res << endl;
    }
    return 0;
}
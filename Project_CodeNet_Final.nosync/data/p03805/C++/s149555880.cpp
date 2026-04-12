#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cmath>
#include <cstdarg>
#include <cstdlib>
#include <string>

#include <vector>
#include <tuple>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

#define MAX_N 10
typedef pair<int, int> pint;

class Permutation{
    int length = 0;
    int target[MAX_N];
    int perm[MAX_N];
    int used[MAX_N];

    stack<pint> stk;

public:
    Permutation(int a[], int n){
        length = n;

        for (int i = length - 1; i>= 0; i --) {
            target[i] = a[i];
            perm[i] = i;
            stk.push(make_pair(0, i));
        }
    }

    bool next_permutation(int res[]) {
        if (stk.empty()) return false;

        pint coor;
        int ind, num;

        for (int i = stk.top().first; i < length; i ++) {
            used[perm[i]] = -1;
        }

        while (!stk.empty()) {
            coor = stk.top();
            stk.pop();
            ind = coor.first;
            num = coor.second;
            perm[ind] = num;
            used[num] = ind;

            if (ind == length - 1) {
                for (int i = 0; i < length; i ++) {
                    res[i] = target[perm[i]];
                }
                return true;
            }

            for(int i = length - 1; i >= 0; i --) {
                if (used[i] == -1) {
                    stk.push(make_pair(ind+1, i));
                }
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    int a[n], b[n][n], res[n];

    int s, t;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            b[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i ++) {
        a[i] = n-i-1;
    }
    res[n-1]=0;


    for (int i = 0; i < m; i ++) {
        cin >> s >> t;
        b[--s][--t] = 1;
        b[t][s] = 1;
    }

    Permutation per = Permutation(a, n-1);
    int count = 0, f;
    while (per.next_permutation(res)) {
        f = 1;
        for(int i = 0; i < n-1; i ++) {
            if (b[res[i]][res[i+1]] == 0) {
                f = 0;
                break;
            }
        }
        count += f;
    }
    cout << count << endl;
    return 0;
}
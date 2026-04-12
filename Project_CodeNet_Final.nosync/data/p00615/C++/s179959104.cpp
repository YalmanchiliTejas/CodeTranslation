#define _SCL_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n, m;
    while (cin >> n >> m && n | m){
        static int l[10000];
        static int r[10000];
        for (int i = 0; i < n; i++)cin >> l[i];
        for (int i = 0; i < m; i++)cin >> r[i];
        static int all[20001];
        all[0] = 0;
        merge(l, l + n, r, r + m, all + 1);
        int res = 0;
        for (int i = 0; i < n + m; i++){
            res = max(res, all[i + 1] - all[i]);
        }
        cout << res << endl;
    }
}
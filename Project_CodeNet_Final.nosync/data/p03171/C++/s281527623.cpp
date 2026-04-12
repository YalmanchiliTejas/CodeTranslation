#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long a[3000], x[3000][3000], y[3000][3000];

void dfs(int left, int right, int turn) { 
    if(left + 1 <= right && x[left+1][right] == 0 && y[left+1][right] == 0) dfs(left+1, right, 1-turn);
    if(left <= right - 1 && x[left][right-1] == 0 && y[left][right-1] == 0) dfs(left, right-1, 1-turn);
    if(turn) {
        if(x[left+1][right]+a[left]-y[left+1][right] > x[left][right-1]+a[right]-y[left][right-1]) {
            x[left][right] = x[left+1][right] + a[left];
            y[left][right] = y[left+1][right];
        } else {
            x[left][right] = x[left][right-1] + a[right];
            y[left][right] = y[left][right-1];
        }
    } else {
        if(x[left+1][right]-y[left+1][right]-a[left] < x[left][right-1]-y[left][right-1]-a[right]) {
            y[left][right] = y[left+1][right] + a[left];
            x[left][right] = x[left+1][right];
        } else {
            y[left][right] = y[left][right-1] + a[right];
            x[left][right] = x[left][right-1];
        }
    }
}

int main() {
    cin >> n;
    for(int i=0;i<n;++i) cin >> a[i];

    dfs(0, n-1, 1);

    cout << x[0][n-1]-y[0][n-1] << "\n";
}
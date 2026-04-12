#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int x[200001], y[200001];

int main(void) {
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        scanf("%d", x+i);
        y[i] = x[i];
    }
    sort(y, y+n+1);
    int half = n/2;
    for(int i=1; i<=n; i++) {
        if(x[i] <= y[half]) printf("%d\n", y[half+1]);
        else printf("%d\n", y[half]);
    }

    return 0;
}
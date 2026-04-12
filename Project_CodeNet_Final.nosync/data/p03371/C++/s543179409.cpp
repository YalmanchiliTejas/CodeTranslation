#include <bits/stdc++.h>
using namespace std;
int A, B, C, X, Y;
int main(){
    cin >> A >> B >> C >> X >> Y;
    int ans = 1e9;
    for(int i = 0; i <= X; i++){
        int s = i * A + 2 * C * (X - i);
        int br = max(0, Y - (X - i));
        s += br * B;
        ans = min(ans, s);
    }
    for(int i = 0; i <= Y; i++){
        int s = i * B + 2 * C * (Y - i);
        int br = max(0, X - (Y - i));
        s += br * A;
        ans = min(ans, s);
    }
    printf("%d\n", ans);
    return 0;
}

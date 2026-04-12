#include <bits/stdc++.h>

using namespace std;


int main(int argc, char *argv[])
{
    
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    
    int Z = 0;
    int min_cost = A * X + B * Y;
    
    while (X > 0 || Y > 0) {
        min_cost = min(min_cost, A * X + B * Y + Z * C);
        X = max(X - 1, 0);
        Y = max(Y - 1, 0);
        Z += 2;
    }
    
    min_cost = min(min_cost, A * X + B * Y + Z * C);
    
    cout << min_cost << endl;
    
    return 0;
}

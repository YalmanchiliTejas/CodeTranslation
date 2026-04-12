#include <bits/stdc++.h>
using namespace std;

int main(void){
    
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    
    long long ans;

        int sheet_Min = min(X, Y);
        int amari_A = X - sheet_Min;
        int amari_B = Y - sheet_Min;
        
        long long piza_AB = (A * X) + (B * Y);
        long long piza_ABC = (amari_A * A) + (amari_B * B) + (sheet_Min * (2 * C));
        long long piza_C = (amari_A * (2 * C)) + (amari_B * (2 * C)) + (sheet_Min * (2 * C));
        
        ans = min({piza_AB, piza_ABC, piza_C});
        
        cout << ans << endl;
}

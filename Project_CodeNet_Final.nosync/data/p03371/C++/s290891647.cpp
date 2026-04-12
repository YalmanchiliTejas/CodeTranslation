#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void){
    ios_base::sync_with_stdio( false );
    int a, b, c, x, y;
    cin >> a >> b >> c >>  x >> y;
    int result = INT_MAX;
    for(int i = 0; i <= max(x, y); i++){
        int tmp = 2 * c * i + max(0, x - i) * a + max(0, y - i) * b;
        if(tmp < result){
            result = tmp;
        }
    }
    cout << result << endl;
}

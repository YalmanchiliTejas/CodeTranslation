#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int A, B, C;
    int X, Y;
    cin >> A >> B >> C >> X >> Y;

    if( A+B <= 2*C ){
        cout << A*X + B*Y << endl;
        return 0;
    }

    int min_c = min({X, Y}) * 2;
    int max_c = max({X, Y}) * 2;

    long long ans = A*X + B*Y;
    for(int c_count=min_c; c_count<max_c+1; c_count++){
        long long price = A*max({X-c_count/2,0}) + B*max({Y-c_count/2,0}) + c_count*C;
        if(ans > price){
            ans = price;
        }
    }

    cout << ans << endl;
    return 0;

}
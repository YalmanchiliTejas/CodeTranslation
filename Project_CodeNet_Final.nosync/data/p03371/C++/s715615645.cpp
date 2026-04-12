#include <bits/stdc++.h>
using namespace std;

int main(){
    int A, B ,C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int sum = A*X + B*Y;
    for(int i = 0; i <= max(X, Y); i++){
        int sum1 = C*2*i;
        if((X-i) > 0){
            sum1 += A*(X-i);
        }
        if((Y-i) > 0){
            sum1 += B*(Y-i);
        }
        sum = min(sum, sum1);
    }
    cout << sum << endl;

    return 0;
}
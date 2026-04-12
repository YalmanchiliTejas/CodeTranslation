#include <iostream>

using namespace std;
int main(){

    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    long ans = 0;
    long long min = 100000000000;
    int K = max(X, Y);
    for(int k=0; k<=K; k++){
        ans = 2*C * k + A * max(0, (X-k)) + B * max(0, (Y-k));
        if(min > ans){
            min = ans;
        }
    }
    cout << min << endl;

    return 0;
}
#include <iostream>

using namespace std;

int minimize(int a, int b){
    int ans = a;
    if (a > b){
        ans = b;
    }
    return ans;
}
int maximize(int a, int b){
    int ans = a;
    if (a < b){
        ans = b;
    }
    return ans;
}

int main(){
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int ans = A * X + B * Y;

    for (int i = 0; i <= (maximize(X, Y)); i ++){
        int sum = A * maximize(0, X - i) + B * maximize(0, Y - i) + C * i * 2;
        if (sum < ans){
            ans = sum;
        }
    }
    
    cout << ans << endl;

    return 0;
}
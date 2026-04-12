#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define MOD 1e9+7
using namespace std;
typedef long long ll;

int main(){
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    int half = C * 2;
    int ab = A + B;

    if(half>=ab){
        cout << A * X + B * Y;
    }else{
        int sum = 0;
        if(X>Y){
            sum += Y * half;
            int num = X - Y;
            sum += num * min(A, half);
        }else{
            sum += X * half;
            int num = Y - X;
            sum += num * min(B, half);
        }
        cout << sum;
    }
}
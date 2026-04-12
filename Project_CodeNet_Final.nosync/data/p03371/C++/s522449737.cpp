#include<bits/stdc++.h>
using namespace std;

int A, B, C;
long X, Y;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> A >> B >> C >> X >> Y;
    long long sum=0;
    if((A+B)/2 >= C){
        long long res1 =0, res2=0;
        long large = X > Y ? X: Y;
        res1 += C * large * 2;
        res2 += min(X, Y) * C * 2;
        long r = X > Y ? A : B;
        res2 += r * (max(X, Y) - min(X, Y));
        sum = min(res1, res2);
    }else{
        sum += A * X + B * Y;
    }
    cout << sum << endl;
}

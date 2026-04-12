#include <bits/stdc++.h>
using namespace std;

long long sum, price;

int main(){
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    for (int i  = 0; i <= 2 * max (X, Y); i += 2){
        price = C * i + A * max(0, X - i / 2) + B * max(0, Y - i /2);
      	if (i == 0) sum = price;
        sum = min(sum, price);
        
    }
    cout << sum << endl;
}
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main(){
int A, B, C, X, Y;
cin >> A >> B >> C >> X >> Y; 
int ans = A * X + B * Y; 
for(int i = 0; i <= max(X, Y); i++){
int T = A * max(X - i, 0) + B * max(Y - i, 0) + C * i * 2; 
ans = min(ans, T); 
}
cout << ans << endl; 
}
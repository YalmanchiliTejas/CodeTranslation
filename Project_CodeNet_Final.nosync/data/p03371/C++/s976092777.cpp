#include <bits/stdc++.h>
using namespace std;
 typedef long long ll;



int main() {
ll A, B, C, X, Y;
cin >>A >> B >> C >> X >> Y;
ll ans = 1000000009;
for(int i = 0; i <= 500000000; i = i+2){
    ll a;
if(i/2 > X) a = 0;
else a = X - i/2; 
ll b;
if(i/2 > Y) b = 0;
else b = Y - i/2; 

ll sumkari = A*a + B*b + C*i;
ans = min(ans, sumkari);

}

cout << ans << endl;

}



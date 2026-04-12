#include<bits/stdc++.h>
using namespace std;

int main(){
    int A, B, C, X, Y, ans = 2e9, tmp, buyX, buyY;
    cin >> A >> B >> C >> X >> Y;

    C *= 2;

    for(int i=0; i<max(X, Y)+1 ; i++){
	buyX = max((X-i), 0);
	buyY = max((Y-i), 0);
	tmp = buyX*A + buyY*B + i*C;
	ans = min(ans, tmp);
    }
    
    cout << ans <<endl;
    
}



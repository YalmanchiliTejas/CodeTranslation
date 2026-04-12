#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main(void){
    
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    
    long long ans = LLONG_MAX;
    
    // ハーフの2枚買ったときの繰り返し（残りはAとBの買ったときを考える）
    for(int i = 0; i <= 100000; i++){
        
        // ０枚からMAX枚のハーフピザを買ったときの値段の繰く返し
        // X - i , Y -i がマイナスの場合は０枚買ったこと
        long long price = (2 * i * C) + max( X - i, 0) * A + max( Y - i, 0) * B;
        ans = min(ans, price);
    }
    
    cout << ans << endl;
}

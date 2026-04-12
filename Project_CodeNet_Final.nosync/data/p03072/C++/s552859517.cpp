#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    
    //入力
    int N;
    cin >> N;
    int mountains[N];
    for (int i = 0; i < N; i++) cin >> mountains[i];
    
    //海を見られる旅館の数をかぞえる
    int tallest_mountain = mountains[0];
    int ans = 1;
    for (int i = 1; i < N; i++){
        if (mountains[i] >= tallest_mountain) {
            ans++;
            tallest_mountain = mountains[i];
        }    
    }
    
    //出力
    cout << ans << endl;
}
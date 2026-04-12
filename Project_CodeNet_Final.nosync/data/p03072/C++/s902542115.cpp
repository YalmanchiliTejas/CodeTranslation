#include <iostream>

using namespace std;

int main(){
    int cnt, h, Max = 0, ans = 0;
    cin >> cnt;
    if(cnt){
        cin >> h;
        Max = h;
        ans++;
    }
    for(int i = 1; i<cnt; i++){
        cin >> h;
        if(h>=Max){
            ans++;
            Max = h;
        }
    }
    cout << ans;
    return 0;
}

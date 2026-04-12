#include <iostream>

using namespace std;

int main(){
    int cnt, h, Max = 0, ans = 0;
    cin >> cnt;
    for(int i=0; i<cnt; i++){
        cin >> h;
        if(h>=Max){
            ans++;
            Max = h;
        }
    }
    cout << ans;
    return 0;
}

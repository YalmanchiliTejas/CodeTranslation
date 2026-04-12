#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N, h, H;
    cin >> N >> H;
    int ans = 1;
    for(int i = 0; i < N-1; i++){
        cin >> h;
        if(H <= h){
            H = h;
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}

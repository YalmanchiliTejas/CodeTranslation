#include <iostream>

using namespace std;
int main() {
    int N;
    cin >> N;
    int count = 0, ans = 0, highest = 0;
    while(count < N){
        count++;
        int H;
        cin >> H;
        if(highest <= H) {
            ans++;
            highest = H;
        }
    }
    cout << ans << endl;
    return 0;
}

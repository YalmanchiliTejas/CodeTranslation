#include <iostream>

using namespace std;


int main(){

    int n;
    cin >> n;
    int h[100];
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    int max = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (h[i] >= max) {
            ans++;
            max = h[i];
        }
    }
    cout << ans << '\n';


}

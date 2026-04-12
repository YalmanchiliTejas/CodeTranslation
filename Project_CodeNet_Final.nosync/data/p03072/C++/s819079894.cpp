#include <iostream>
#include <vector>

using namespace std;

int main(){

    int N;
    cin >> N;
    
    vector<int> H(N);
    
    for (int i = 0; i < N; i ++) {
        cin >> H[i];
    }
    
    int ans = 1;
    int see = 0;
    
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (H[j] > H[i]) {
                see = 1;
            }
        }
        if (see == 0) {
            ans += 1;
        }
        see = 0;
    }
    
    
    cout << ans << endl;
    
    
    
    
    
    return 0;
    
}

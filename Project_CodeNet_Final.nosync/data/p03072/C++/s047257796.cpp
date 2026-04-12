#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
 
int main() {
    int N;
    cin >> N;

    int H[N];

    for(int i = 0; i < N; i++) {
        cin >> H[i];
    }

    int ans = 1;
    
    for(int i = 1; i < N; i++) {
        int j;

        for(j = 0; j < i; j++) {
            if(H[i] < H[j]) {
                break;
            }
        } 

        if(j == i) {
            ans++;
        }
    }

    cout << ans;
    
    cout << endl;
    return 0;
}
#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    int H[21];
    
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }
    
    int ans = 1;
    int cnt = 0;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if(H[i] < H[j]) ++cnt;
        }
        if(cnt == 0) ++ans;
        cnt = 0;
    }
    
    cout << ans << endl;
    
}

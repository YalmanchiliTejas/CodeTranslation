#include <iostream>

using namespace std;

int main(){
    int N;
    int H[100];
    int ans = 1;
    cin >> N;
    for(int i = 0; i < N; i++) cin >> H[i];
    for(int i = 1; i < N; i++){
        for(int j = 0; j < i; j++){
            if(H[i] < H[j]) break;
            if(j == i-1) ans++;
        }
    }
    cout << ans << endl;
}
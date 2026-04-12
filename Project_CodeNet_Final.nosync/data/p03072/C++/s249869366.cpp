#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int ans = 0;
    int N;
    cin >> N;
    
    int H[N];    
    for(int i = 0; i < N; i++){
        cin >> H[i];
    }

    for(int i = 0; i < N; i++){
        if(*max_element(H, H + i) <= H[i]){
            ans++;
        }
    }
    cout << ans << endl;
}

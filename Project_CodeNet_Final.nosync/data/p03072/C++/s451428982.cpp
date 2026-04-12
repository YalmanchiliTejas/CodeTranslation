#include <iostream>
using namespace std;

int main(){
    int N, H[100], ans = 0;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> H[i];
    }
    for(int i = 1; i < N; i++){
        bool  isView = true;
        for(int j = 0; j < i; j++){
            if(H[j] > H[i]){
                isView = false;
                break;
            }
        }
        if(isView){
            ans++;
        }
    }
    cout << ans+1 << endl;
    return 0;
}

#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int h[n];
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    int ans = 0;
    for(int i = n-1; i >= 0; i--){
        bool visible = true;
        for(int j = i-1; j >= 0; j--){
            if(h[i] < h[j]){
                visible = false;
                break;
            }
        }
        if(visible){
            ans++;
        }
    }
    cout << ans << endl;
}
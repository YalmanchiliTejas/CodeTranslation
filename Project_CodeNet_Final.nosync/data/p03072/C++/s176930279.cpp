#include <iostream>
using namespace std;

int n;
int main(void){
    // Your code here!
    cin >> n;
    int H[n];
    for(int i = 0; i < n; i++){
        cin >> H[i];
    }
    
    bool flag = true;
    
    int cnt = 1;
    for(int i = 1; i < n; i++){
        flag = true;
        for(int j = 0; j < i; j++){
            if(H[j] > H[i]) {
                flag = false;
                break;
            }
        }
        
        if(flag) {
            cnt += 1;
        }
    }
    
    cout << cnt << endl;
}

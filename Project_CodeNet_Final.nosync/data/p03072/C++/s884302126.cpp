#include <iostream>
#include <vector>
using namespace std;
int main(void){
    // Your code here!
    int N;
    cin >> N;
    
    vector<int> mtn(N);
    for (int i = 0; i < N; i++) cin >> mtn[i];
    
    int max_height = mtn[0];
    int ans = 1;
    
    for (int i = 1; i < N; i++){
        if (mtn[i] >= max_height) {
            max_height = mtn[i];
            ans += 1;
        }   
    }
    
    cout << ans << endl;
}
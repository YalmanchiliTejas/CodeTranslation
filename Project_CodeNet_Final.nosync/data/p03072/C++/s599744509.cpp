#include <iostream>
#include <vector>
using namespace std;
int tall;
int main(void){
    // Your code here!
    int N;
    cin >> N;
    
    vector<int> Ryokan(N);
    
    int ans;
    ans = 0;
    
    for (int i = 0; i < N; i++) cin >> Ryokan[i];
    
    tall = Ryokan[0];
    
    for (int i = 1; i < N; i++){
        if (tall <= Ryokan[i]){
            ans += 1;
            tall = Ryokan[i];
        }
    }
    
    cout << ans + 1 << endl;
    
    
    
    
    
}
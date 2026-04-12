#include <iostream>
#include <vector>
using namespace std;
int main(void){
    // Your code here!
    int N;
    cin >> N;
    vector<int> mountain(N);
    for (int i = 0; i < N; i++) cin >> mountain[i];
    int max = mountain[0];
    int ans = 1;
    for (int i = 1; i < N; i++){
        if (mountain[i] >= max){
            max = mountain[i];
            ans++;
        } 
    }
    cout << ans << endl;
    
}
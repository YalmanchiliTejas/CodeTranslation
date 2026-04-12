#include <iostream>
#include <vector>
using namespace std;
int main(void){
    int n;
    cin >> n;
    vector<int> mtn(n);
    
    for (int i = 0; i < n; i++) cin >>mtn[i];
    
    int h_m = mtn[0];
    int ans = 0;
    
    for (int i = 1; i < n; i++){
        if (mtn[i] >= h_m) {
            h_m = mtn[i];
            ans++;
        }
    }
    
    cout << ans + 1 << endl;
}
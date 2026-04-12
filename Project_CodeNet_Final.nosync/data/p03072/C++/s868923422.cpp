#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int main(void){
    int n,mx;
    cin >> n;
    vector<int> h(n);
    for(int i = 0;i < n;i++) cin >> h[i];
    mx = h[0];
    int ans = 1;
    for(int i = 1;i < n;i++){
        if(h[i] >= mx){
            ans++;
            mx = h[i];
        }
    }
    cout << ans << endl;
    return 0;
}

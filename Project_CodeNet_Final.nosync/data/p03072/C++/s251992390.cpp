#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> h(n);
    int ans = 0;
    int max = 0;
    for(int i = 0; i < n; i++){
        cin >> h[i];
        if(max <= h[i]){
            max = h[i];
            ans++;
        }
    }

    cout << ans << endl;
    return 0;

    
}

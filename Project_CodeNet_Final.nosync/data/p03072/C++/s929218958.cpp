#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(){
    int n, a=0;
    cin >> n;
    int h[n];
    for(int i=0; i<n; ++i) cin >> h[i];
    int ans = 0;

    for(int i=0; i<n; ++i){
        if(h[i]>=h[a]){
            ++ans;
            a = i;
        }
    }
    cout << ans << endl;

    return 0;
}


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    int h[21];

    for(int i=0; i<n; i++){
        cin >> h[i];
    }

    int hmin;
    hmin = h[0];
    int ans = 1;
    for(int i=1; i<n; i++){
        if(hmin <= h[i]){
            ans++;
            hmin = h[i];
        }
    }
    cout << ans << endl;
    return 0;
}
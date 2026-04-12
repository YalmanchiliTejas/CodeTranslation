#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100 + 10;
int h[maxn];

int main(){
    int n = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    int ans = 1, hn = h[0];
    for(int i = 1; i < n; i++){
        if(hn <= h[i]){
            //cout << h[i] << ' ' << i << endl;
            ans++;
        }
        hn = max(hn, h[i]);
    }
    cout << ans << endl;
    return 0;
}

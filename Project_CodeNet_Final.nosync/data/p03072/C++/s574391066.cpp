#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n; cin >> n;
    int max_h=-1, ans=0;
    for(int i=0; i<n; ++i){
        int h; cin >> h;
        if(h>=max_h) ++ans;
        max_h=max(max_h, h);
    }
    cout << ans << endl;
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, m=0, cnt=0;
    cin >> n;

    vector<int>h(n);
    for(int i=0; i<n; i++){
        cin >> h[i];
        if(h[i]>=m) cnt++;
        m = max(h[i], m);
    }

    cout << cnt << endl;

    return 0;
}
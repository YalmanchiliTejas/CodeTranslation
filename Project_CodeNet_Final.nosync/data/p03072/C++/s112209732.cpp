#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n,h_max,cnt,i;
    cnt = 1;
    cin >> n;
    vector<int> h(n+1);
    cin >> h.at(1);
    h_max = h.at(1);

    for(i=2; i<=n; i++){
        cin >> h.at(i);
        if(h.at(i) - h_max >= 0){
            cnt++;
        }
        h_max = max(h_max,h.at(i));
    }
    cout << cnt << endl;
    return 0;
}
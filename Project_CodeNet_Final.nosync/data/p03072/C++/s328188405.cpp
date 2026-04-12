#include <bits/stdc++.h>
#define ALL(a)  (a).begin(),(a).end()
using namespace std;
int main(){
    int n;
    cin>> n;
    vector<int> h(n);
    for(int i = 0; i < n; ++i){
        cin >> h[i];
    }

    int ans = 1;
    bool can;

    for(int i = 1; i < n; ++i){
        can = true;
        for(int j = 0; j < i; ++j){
            
            if(h[j] > h[i]){
                can = false;
            }
        }
        if(can) ans++;
    }

    cout << ans << endl;

}
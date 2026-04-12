#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int ans = 1;
    int big; cin >> big;

    for(int i=1; i<n; i++){
        int high; cin >> high;
        if(big <= high){
            big = high;
            ans++;
        }
    }

    cout << ans << endl;
}
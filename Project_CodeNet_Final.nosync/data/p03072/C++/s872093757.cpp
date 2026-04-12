#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    int ans = 0;
    int h_max = 0;
    cin >> n;
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        if(h_max<=tmp){
            h_max = tmp;
            ans++;
        }
    }
    cout << ans << endl;
}

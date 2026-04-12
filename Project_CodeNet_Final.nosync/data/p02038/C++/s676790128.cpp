#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string ans = "T";
    for(int i=0;i<n;i++){
        string p;
        cin >> p;
        if(ans=="T"){
            ans = p;
        }
        else{
            ans = "T";
        }
    }
    cout << ans << endl;
    return 0;
}


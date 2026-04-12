#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    int top = 0;
    int result = 0;
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        if(val >= top){
            result ++;
            top = val;
        }
    }
    cout << result;
    return 0;
}

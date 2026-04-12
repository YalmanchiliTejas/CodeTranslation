/*|In The Name of Allah|*/

#include <bits/stdc++.h>

using namespace std;

const int N = 7e3+5;

int n;

int main(){
    cin >> n;
    int mx = 0 , cnt = 0;
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        if(x >= mx){
            cnt++;
        }
        mx = max(mx , x);
    }
    cout << cnt << endl;
    return 0;
}


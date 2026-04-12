#include <bits/stdc++.h>
using namespace std;
int main(){
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    while(b*ans + c*(ans+1) <= a){
        ans++;
    }
    cout << ans-1 << endl;
    return 0;
}
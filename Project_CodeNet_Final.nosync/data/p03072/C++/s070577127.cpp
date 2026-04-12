#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,h,ans = 1; 
    cin >> n >> h;
    for (int i = 0; i < n-1; i++){
        int a;
        cin >> a;
        if(a >= h)ans++;
        if(a > h)h = a;
    }
    cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
    int n;
    cin >> n;
    int ans = 0;
    int maxh = 0;
    for(int i=0;i<n;i++){
        int h;
        cin >> h;
        maxh = max(maxh,h);
        if(maxh == h){
            ans ++;
        } 
    }
    cout << ans << endl;
}
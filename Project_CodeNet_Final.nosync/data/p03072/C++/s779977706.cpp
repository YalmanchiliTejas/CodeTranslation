#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n, h, ans=0, ma=0;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> h;
        if(ma<=h){
            ans++;
            ma=h;
        }
    }
    cout << ans << endl;
}
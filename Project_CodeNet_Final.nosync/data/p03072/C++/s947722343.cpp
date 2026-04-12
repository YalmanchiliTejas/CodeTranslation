#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    int h[25];
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    int ans = 1;
    for(int i = 1; i < n; i++){
        int ch = 1;
        for(int j = 0; j < i; j++){
            if(h[j] <= h[i])continue;
            else{
                ch = 0;
                break;
            }
        }
        if(ch == 1){
            ans++;
        }
    }
    cout << ans << endl;
}
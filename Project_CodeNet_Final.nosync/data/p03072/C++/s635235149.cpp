#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    int n;
    cin >> n;
    int h[n];
    rep(i, n){
        cin >> h[i];
    }
    int cnt=1;
    for(int i=1;i<n;i++){
        bool f=true;
        for(int j=0;j<i;j++){
            if(h[j]>h[i]){
                // cout << i << " " << j << endl;
                f = false;
            }
        }
        if(f){
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
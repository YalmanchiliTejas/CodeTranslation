#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,ans(0),max;

    cin >> n;
    int h[n];

    for(int i=0;i<n;i++)
        cin >> h[i];

    max = h[0];
    for(int i=0;i<n;i++){
        if(max<h[i])
            ans++;
        if(max==h[i]){
            ans++;
            max = h[i];
        } 
        if(max<h[i])
            max = h[i];
    }

    cout << ans << endl;
}
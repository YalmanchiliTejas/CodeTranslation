#include<cstdio>
#include<iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int h[n];
    for(int i = 0; i < n; i++){
        cin >> h[i];
    }
    int height = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if (height <= h[i]) {
            height = h[i];
            ans++;
        }
    }
    cout << ans << '\n';

}
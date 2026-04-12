#include <bits/stdc++.h>
using namespace std;

int n, h[25], t;

int main() {
    cin >> n;
    for(int i=0; i<n; i++) cin >> h[i];
    for(int i=0; i<n; i++){
        int x=0;
        for(int j=0; j<i; j++){
            if(h[j] <= h[i]){
                x++;
            }
        }
        if(x==i){
            t++;
        }
    }
    cout << t;
}
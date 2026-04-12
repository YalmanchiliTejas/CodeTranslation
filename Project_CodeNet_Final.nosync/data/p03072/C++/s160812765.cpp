#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n,maxh = 0; cin >> n;
    int i = 0, u = 0;
    while(i < n){
        int h; cin >> h;
        if(h >= maxh){
            u++;
            maxh = h;
        }
        i++;
    }
    cout << u;
    return 0;
}
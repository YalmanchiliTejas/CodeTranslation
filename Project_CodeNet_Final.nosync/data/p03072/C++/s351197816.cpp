#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, i, h, hm = 0, c = 0;
    cin >> n;
    for(i=0; i<n; i++){
        cin >> h;
        if(h >= hm){
            c++;
            hm = h;
        }
    }
    cout << c;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, i, h;
    cin >> n;
    int mx = -1, c = 0;
    for(i = 0; i < n; i++){
        cin >> h;
        if(mx <= h){
            c++;
            mx = h;
        }
    }
    cout << c << endl;
}
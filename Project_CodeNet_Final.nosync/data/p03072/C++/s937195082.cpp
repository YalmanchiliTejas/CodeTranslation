#include <bits/stdc++.h>
using namespace std;



int main(){
    int n, h, cont = 0;
    cin >> n;
    int maxi = 0;
    for (int i=0; i < n; ++i){
        cin >> h;
        if (h >= maxi) cont++;
          maxi = max(maxi, h);
        
    }
    cout << cont;
}
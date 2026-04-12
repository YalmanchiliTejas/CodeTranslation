#include <bits/stdc++.h>
using namespace std;

int main(){

    int h[10004], n;
    cin >> n;
    for(int i=0; i<n; i++) cin >> h[i];

    int min = h[0], cont=0;
    for(int i=0; i<n; i++){
        if(h[i] >= min) cont++;
        min = max(h[i], min);
    }
    cout << cont << endl;
    
    return 0;
}
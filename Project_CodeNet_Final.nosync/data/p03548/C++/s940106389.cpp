#include <bits/stdc++.h>
using namespace std;

int main(){
    int x,y,z;
    cin >> x >> y >> z;
    int ans;
    for(int i=0;i<x;i++){
        if(y*i + z*(i+1) > x){
            ans = i-1;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
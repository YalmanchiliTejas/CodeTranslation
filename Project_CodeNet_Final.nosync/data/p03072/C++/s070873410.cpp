#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, h[200], maxx=0, sum=0;
    cin >> n;

    for(int i=0; i<n; i++){
       cin >> h[i];
       if(h[i] >= maxx){
            sum++;
            maxx = h[i];
       }
    }
    cout << sum << endl;
}

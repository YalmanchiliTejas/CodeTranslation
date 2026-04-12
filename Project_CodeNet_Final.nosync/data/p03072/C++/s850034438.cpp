#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    int ans = 0;
    for(int i = 0; i < n; ++i){
        int poss = 1; //It is true that index i is greater than [0, i -1]
        //Assuming
        for(int j = i - 1; j >= 0; j = j - 1){
            if( a[j] > a[i]){
                 poss = 0; //Our assumption fails
                 break;
            }
        }
        if(poss == 1){
            ans = ans + 1;
        } 
    }
    cout << ans << '\n';
}
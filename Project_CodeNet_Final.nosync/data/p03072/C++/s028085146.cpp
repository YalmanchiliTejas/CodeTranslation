#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    int H[100];
    for(int i=0;i<N;i++){
        cin >> H[i];
    } 
    int ans = 0;
    int highest = -1;
    for(int i=0;i<N;i++){
        if(H[i] >= highest){
            ans += 1;
            highest = H[i];
        } 
    }
    cout << ans << endl;
}
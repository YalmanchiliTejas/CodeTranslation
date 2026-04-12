#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main(){ 
    int N;
    cin >>N;
    int H[N];
    for(int i = 0;i < N;i++) cin >> H[i];
    int ans = 0;
    int memo = -1;
    for(int i = 0;i < N;i++){
        if(H[i] >= memo){
            memo = H[i];
            ans++;
        }
    }
    cout << ans << endl;
}
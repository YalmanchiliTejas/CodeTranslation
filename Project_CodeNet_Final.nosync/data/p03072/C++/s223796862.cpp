#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,ans = 0,max = -1;
    cin >> N;
    vector<int> H(N);
    
    for(int i = 0;i < N;i++){
        cin >> H.at(i);
    }

    for(int i = 0;i < N;i++){
        if(max <= H.at(i)){
            max = H.at(i);
            ans++;
        }
    }

    cout << ans << endl;
}
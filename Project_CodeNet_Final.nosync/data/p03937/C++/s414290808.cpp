#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll H,W;
    cin >> H >> W;
    ll num =0;
    for(int i=0;i<H;i++){
        string S;
        cin >> S;
        for(int j=0;j<W;j++){
            if(S[j] =='#'){
                num++;
            }
        }
    }
    if(num == H +W-1){
        cout <<"Possible" << endl;
    }else{
        cout <<"Impossible"<< endl;
    }

    return 0;
}
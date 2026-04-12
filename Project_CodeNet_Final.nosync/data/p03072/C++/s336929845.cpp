#include<bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    vector<int> H(N);
    for(int i=0;i<N;i++){
        cin >> H[i];
    }
    int max = H[0];
    int cnt = 0;
    for(int i=0;i<N;i++){
        if(max<=H[i]){
            cnt++;
        }
        if(max<H[i]){
            max = H[i];
        }
    }
    cout << cnt << endl;
}
#include <bits/stdc++.h>
using namespace std;

int OceanView(int N){
    int H[N]={};
    for(int i=0;i<N;i++){
        cin >> H[i];
    }
    int cnt=1;
    for(int i=1;i<N;i++){
        bool flg=false;
        for(int j=0;j<i;j++){
            if(H[j]<=H[i]){
                flg=true;
            }
            else{
                flg=false;
                break;
            }
        }
        if(flg==true){
            cnt++;
        }
    }
    return cnt;
}
int main(){
    int N; cin >> N;
    cout << OceanView(N) << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;



int main(){
    int N,cnt=1;
    cin >> N;
    int H[N]={0};
    for(int i=0;i<N;++i) cin >> H[i];

    bool flag = true;
    for(int i=1;i<N;++i){
        for(int j=0;j<i;++j){
            if(H[i]<H[j]){
                flag = false;
                break;
            }
        }
        if(flag){
            cnt += 1;
        }
        flag = true;
    }
    cout << cnt << endl;
}




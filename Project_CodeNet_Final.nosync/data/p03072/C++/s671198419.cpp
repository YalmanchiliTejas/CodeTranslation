#include <bits/stdc++.h>
using namespace std;

//関数
//main関数
int main() {
    
    
    //入力
    long N;
    cin>>N;
    vector<long> H(N);
    for(int i=0;i<N;i++){
        cin>>H.at(i);
    }
    //計算
    long ans=1,highest=H.at(0);
    for(int i=1;i<N;i++){
        if(H.at(i)>=highest){
            ans++;
            highest=H.at(i);
        }
    }
    
    //出力
    cout<<ans<<endl;
}




#include <bits/stdc++.h>
using namespace std;
//関数
const long INF=1000000000000;

//main関数
int main() {
    //入力
    long N;
    cin>>N;
    vector<long> A(N);
    for(int i=0;i<N;i++){
        cin>>A.at(i);
    }
    
    //計算
    sort(A.begin(),A.end());
    long ave=A.at((N-1)/2);
   // cout<<"ave"<<ave<<endl;
    long ans=0;
    for(int i=0;i<N;i++){
        ans+=2*abs(A.at(i)-ave);
//cout<<A.at(i)<<"を加え"<<ans<<"に"<<endl;
    }
    
    
    if(N%2==1){
        ans-=min(A.at(N/2+1)-A.at(N/2),A.at(N/2)-A.at(N/2-1));
    }else{
        ans-=A.at(N/2)-A.at(N/2-1);
    }
    
    //出力
    cout<<ans<<endl;
}
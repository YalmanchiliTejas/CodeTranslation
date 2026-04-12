#include<bits/stdc++.h>
using namespace std;

int main(void){
    int N,max=0,cnt=0;
    cin>>N;
    int H[N];
    for(int i=0;i<N;i++){
        cin>>H[i];
        if(H[i]>=max){
            max=H[i];
            cnt++;
        }
    }
    cout<<cnt<<endl;
    return 0;
}

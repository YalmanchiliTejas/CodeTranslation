#include<iostream>
using namespace std;

int main(){
    int N,H[21],max_h=-1,cnt=0;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>H[i];
        if(H[i]>=max_h){
            cnt++;
        }
        max_h=max(max_h,H[i]);
    }
    cout<<cnt<<endl;

    return 0;
}

#include <iostream>
using namespace std;
int main(void){
    int N,dg[300001]={},db[300001]={},checkg=0,checkb=0;
    cin>>N;
    for(int i=0;i<N;i++){
        int a;cin>>a;a/=10;
        if(i+1<300001)dg[i+1]++;
        if(i+1+a<300001)dg[i+1+a]--;
        if(0<=i-1)db[i-1]++;
        if(0<=i-1-a)db[i-1-a]--;
    }
    for(int i=1;i<N;i++){
        dg[i]+=dg[i-1];
        db[N-1-i]+=db[N-i];
    }
    for(int i=0;i<N;i++){
        if(dg[i]==0)checkg++;
        if(db[i]==0)checkb++;
    }
    if(checkg>1 || checkb>1)cout<<"no"<<endl;
    else cout<<"yes"<<endl;
    return 0;
}


#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    int H[100];
    int a=1;
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>H[i];
    }
    for(int k=2;k<=N;k++){
    static int Hmax=H[1];
    if(Hmax<=H[k]){
        Hmax=H[k];
        a+=1;
        }
    }
    cout<<a<<endl;
    return 0;
}
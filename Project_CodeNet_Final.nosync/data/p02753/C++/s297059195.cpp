#include <bits/stdc++.h>
using namespace std;
int main(void){
    string S;
    cin>>S;
    int count=0;
    for(int i=1;i<3;i++){
        if(S[i]==S[i-1]){
            count++;
        }
    }
    if(count==2){
        cout<<"No"<<endl;
        return 0;
    }
    else{
        cout<<"Yes"<<endl;
    }
    return 0;
}

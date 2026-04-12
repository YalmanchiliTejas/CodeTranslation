#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

ll MIN(ll num1,ll num2){
    return num1<num2?num1:num2;
}

int main(){

    int H,W,cnt=0;
    cin>>H>>W;
    for(int i=0;i<H;i++){
        string S;
        cin>>S;
        for(int i=0;i<W;i++){
            if(S[i]=='#')cnt++;
        }
    }
    if(cnt==H+W-1)cout<<"Possible"<<endl;
    else cout<<"Impossible"<<endl;

    return 0;
}
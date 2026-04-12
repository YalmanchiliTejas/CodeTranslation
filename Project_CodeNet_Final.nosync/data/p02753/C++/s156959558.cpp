#include<bits/stdc++.h>
#define ll long long
#define MOD 1e9+7;

using namespace std;

int main(){
    string S;
    cin>>S;
    int ca=0,cb=0;
    for(int i=0;i<S.length();i++){
        if(S[i]=='A'){ca++;}
        else{
            cb++;
        }
    }
    if(ca==0||cb==0){
        cout<<"No"<<endl;
    }else{
        cout<<"Yes"<<endl;
    }

    return 0;
}

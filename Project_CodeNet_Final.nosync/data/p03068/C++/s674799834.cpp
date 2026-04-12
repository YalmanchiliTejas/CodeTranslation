#include<bits/stdc++.h>
using namespace std;
int main(){
    string S;
    int k,n;
    cin>>n>>S>>k;
    for(int i=0;i<S.size();i++){
        if(S[i]!=S[k-1]){
            S[i]='*';
        }
    }
    cout<<S<<endl;
    return 0;
}
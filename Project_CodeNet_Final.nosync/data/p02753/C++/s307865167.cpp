#include <bits/stdc++.h>
using namespace std;
int main(){
    string A;
    cin>>A;
    bool contain_A=false;
    bool contain_B=false;
    for(int i=0;i<A.size();i++){
        if(A[i]=='A')
            contain_A=true;
        else if(A[i]=='B')
            contain_B=true;
        if(contain_A==true&&contain_B==true){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}
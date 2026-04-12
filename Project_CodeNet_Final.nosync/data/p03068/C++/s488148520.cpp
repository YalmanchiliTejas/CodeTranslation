#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin>>N;
    string S;
    cin >>S;
    int z,n;
    cin>>z;
    n=S.size();
    for(int i=0;i<N;i++){
        if(S.at(i)!=S.at(z-1)){
            S.at(i)='*';
        }
    }
    cout << S<<endl;
    
    
    
}

#include <bits/stdc++.h>
using namespace std;


int main(void){
    int n;
    string ox;
    cin>>n>>ox;
    vector<int> ss(n);
    
    for(auto a0:{-1,1})for(auto a1:{-1,1}){
        ss[0]=a0;ss[1]=a1;
        
        for(int i=2;i<=n+1;i++){
            bool c1=ss[(i-1)%n]==1, c2=ox[(i-1)%n]=='x';
            ss[i%n]=ss[(i-2)%n] * (c1 xor c2 ? 1 : -1);
        }
    
        if(ss[0]==a0 and ss[1]==a1){
            for(int i=0;i<n;i++){
                cout<<(ss[i]==1?'S':'W');
            }
            cout<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
}

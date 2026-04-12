#include <bits/stdc++.h>
using namespace std;


int main(void){
    int n;
    cin>>n;
    string ox;
    cin>>ox;
    vector <int> ss(n+1);
    ss[0]= 1;ss[1]= 1;
    
    for(int j=0;j<4;j++){
    
    for(int i=2;i<=n;i++){
        if(ss[i-1]==1){
            if(ox[i-1]=='o'){
                ss[i]=ss[i-2];
            }else{
                ss[i]=ss[i-2]*(-1);
            }
        }else{
            if(ox[i-1]=='o'){
                ss[i]=ss[i-2]*(-1);
            }else{
                ss[i]=ss[i-2];
            }
        }
    }

    if((ss[0]==ss[n])&&(
        ((ox[0]=='o')&&(ss[0]==1)&&(ss[1]==ss[n-1]))||((ox[0]=='x')&&(ss[0]==1)&&(ss[1]!=ss[n-1]))||((ox[0]=='o')&&(ss[0]==-1)&&(ss[1]!=ss[n-1]))||((ox[0]=='x')&&(ss[0]==-1)&&(ss[1]==ss[n-1]))
        )){
        for(int i=0;i<n;i++){
            if(ss[i]==1) cout<<'S';
            else cout<<'W';
        }
        cout<<endl;
        return 0;
    }
    
    if(j%2==0) ss[0]*=(-1);
    else ss[1]*=(-1);
    
    }
    cout<<-1<<endl;
    return 0;
}

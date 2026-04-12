#include<iostream>
using namespace std;
int main(){
    int n;
    string s;
    cin>>n>>s;
    bool p[4][n];
    p[0][0]=p[0][1]=p[1][0]=p[2][1]=true;
    p[1][1]=p[2][0]=p[3][0]=p[3][1]=false;
    for(int i=1;i<n-1;i++)for(int k=0;k<4;k++)p[k][i+1]=p[k][i-1]^(s[i]!='o')^(!p[k][i]);
    for(int k=0;k<4;k++){
        if((p[k][n-2]==p[k][0])==(p[k][n-1])^(s[n-1]!='o')&&(p[k][n-1]==p[k][1])==(p[k][0])^(s[0]!='o')){
            for(int i=0;i<n;i++)cout<<(p[k][i]?'S':'W');
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}
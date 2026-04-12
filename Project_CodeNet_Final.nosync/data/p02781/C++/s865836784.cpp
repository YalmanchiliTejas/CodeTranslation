#include <iostream>
using namespace std;
int dp0[101][4],dp1[101][4],k,n;
string s;
int main(void){
    cin>>s>>k;
    dp1[0][0]=1;
    for(int i=1;i<=s.size();i++){
        if(i>1)dp0[i-1][0]=1;
        n=s[i-1]-'0';
        //cout<<n<<"W"<<endl;
        if(n!=0){
            for(int j=0;j<3;j++){
                dp1[i][j+1]=dp1[i-1][j];
                dp0[i][j+1]=(n-1)*dp1[i-1][j]+9*dp0[i-1][j]+dp0[i-1][j+1]+dp1[i-1][j+1];
            }
        //cout<<dp0[1][0]<<endl;    
        }
        else{
            for(int j=1;j<=3;j++){
                dp1[i][j]=dp1[i-1][j];
                dp0[i][j]=9*dp0[i-1][j-1]+dp0[i-1][j];
            }
            //cout<<dp0[1][0]<<endl;
        }
    }
    cout<<dp0[s.size()][k]+dp1[s.size()][k]<<endl;
}

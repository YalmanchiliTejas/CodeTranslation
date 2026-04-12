#include <iostream>
#include <string>
#include <vector>
using ll=long long;
using namespace std;

int main(){
    string N;
    cin>>N;
    int K;
    cin>>K;

    int L=N.size();

    vector<vector<ll>> dp1(L+1,vector<ll>(K+1,0));
    vector<vector<ll>> dp2(L+1,vector<ll>(K+1,0));

    dp1[0][0]=1;
    dp2[0][0]=1;
    for(int i=1;i<L+1;i++){
        dp1[i][0]=1;
        dp2[i][0]=1;
        int thisnum=(int)N[L-i]-'0';
        for(int j=1;j<K+1;j++){
            if(thisnum!=0){
                dp1[i][j]=dp2[i-1][j]+dp2[i-1][j-1]*(thisnum-1)+dp1[i-1][j-1];
            }else{
                dp1[i][j]=dp1[i-1][j];
            }
            dp2[i][j]=dp2[i-1][j]+dp2[i-1][j-1]*9;
        }
    }
    /*
    for(int i=0;i<L+1;i++){
        for(auto p:dp1[i]){
            cout<<p<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<L+1;i++){
        for(auto p:dp2[i]){
            cout<<p<<" ";
        }
        cout<<endl;
    }
    //*/

    cout<<dp1[L][K]<<endl;

    return 0;
}
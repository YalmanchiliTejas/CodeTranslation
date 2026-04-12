#include<bits/stdc++.h>
using namespace std;
string K;
long long P = 1e9+7;
long long D;

long long dp[100010][110][2];

long long f(int pos, long long sum , bool sw){
    if(pos == (int)K.size()){
        if(sum == 0) return 1;
        else return 0;
    }
    long long &re = dp[pos][sum][sw];
    if(re!=-1) return re;
    re = 0;
    if(sw == 0){
        for(int i = 0 ; i < 10 ; i++){
            re += f(pos+1,(sum%D+i%D)%D,0)  ;
            re %=P;
        }
    }else{
        for( int i = 0; i <= int(K[pos]-'0') ; i++){
            if(i == int(K[pos]-'0')){
                re+=f(pos+1,(sum%D+i)%D,1);
                re %=P;
            } 
            else{
                re += f(pos+1,(sum%D+i)%D,0);
                re %=P;
            } 
        }
    }

    return re;
}
int main(){
    while(cin>>K>>D){
        memset(dp,-1,sizeof dp);
        cout<<(f(0,0,1)-1+P)%P<<"\n";
    }
    return 0;
}
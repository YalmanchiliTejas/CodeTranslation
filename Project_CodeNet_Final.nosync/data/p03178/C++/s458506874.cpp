#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

string str;
int d;
long long dp[10005][2][101];

long long solution(int n , int tight , int mo){

if(n==str.size()){
    return (mo==0) ? 1 : 0;
}
if(dp[n][tight][mo] != -1){
    return dp[n][tight][mo];
}

int en = tight ? (str[n]-'0') : 9;

long long ret = 0;

for(int i=0 ; i<=en ; i++){
    ret = (ret + solution(n+1 , tight&(en==i) , (mo+i)%d)%mod);
}

return dp[n][tight][mo] = ret;


}


int main(){

    cin>>str>>d;
    memset(dp , -1 , sizeof(dp));
    cout<<(solution(0 , 1 , 0)-1+mod)%mod<<endl;
    
}

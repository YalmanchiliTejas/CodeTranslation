#include <bits/stdc++.h>
using namespace std;
 
int main(){
 string N;
 int K;
 int i;
 cin >> N >> K;
 long long int ans = 0;
 if(K==1){
     ans = (N.length()-1)*9 + (N[0]-'0');
 }
else if(K==2){
    ans = ((N.length()-1)*(N.length()-2)*81/2);
    ans += (N[0]-'0'-1)*(N.length()-1)*9;
    int find = 0;
    for(i=1;i<N.length();i++){
        if(N[i]-'0'>0){
            find=i;
            break;
        }
    }
    if(find>0)ans += (N.length()-find-1)*9+(N[find]-'0');
}
else if(K==3){
    ans = ((N.length()-1)*(N.length()-2)*(N.length()-3)*243/2);
    ans += (N[0]-'0'-1)*((N.length()-1)*(N.length()-2)*81/2);
    long long int dp[N.length()][K];
    dp[0][0]=1;
    dp[0][1]=0;
    dp[0][2]=0;
    int find1=0;
    int find2=0;
    for(i=1;i<N.length();i++){
        if(find1==0 && N[i]-'0'>0)find1=i;
        else if(find1>0 && N[i]-'0'){
            find2=i;
            break;
        }}
    if(find1>0){
        ans+=(N.length()-find1-1)*(N.length()-find1-2)*81/2;
        ans+=(N[find1]-'0'-1)*(N.length()-find1-1)*9;
        if(find2>0)ans+=(N.length()-find2-1)*9+(N[find2]-'0');
}}
cout << ans << endl;
}
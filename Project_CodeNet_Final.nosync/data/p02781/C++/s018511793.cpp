#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<int>;
using vvi=vector<vi>;
int ctoi(char c){return (int)c-(int)'0';}
int main() {
    string N;
    int K;
    cin>>N>>K;
    int d=N.size();
    vvi dp0(d,vi(K,0));
    vvi dp1(d,vi(K,0));
    dp0[0][0]=ctoi(N[0])-1;
    dp1[0][0]=1;
    for (int i = 1; i < d; i++){
        dp0[i][0]=dp0[i-1][0]+9;
        if(ctoi(N[i])>0)dp0[i][0]+=dp1[i-1][0];
        else dp1[i][0]=dp1[i-1][0];
        for (int k = 1; k < K; k++){
            dp0[i][k]=dp0[i-1][k-1]*9+dp0[i-1][k];
            if(ctoi(N[i])>0){
                dp0[i][k]+=dp1[i-1][k-1]*(ctoi(N[i])-1)+dp1[i-1][k];
                dp1[i][k]=dp1[i-1][k-1];
            }else dp1[i][k]=dp1[i-1][k];
        }
    }
    cout<<dp0[d-1][K-1]+dp1[d-1][K-1]<<endl;
}
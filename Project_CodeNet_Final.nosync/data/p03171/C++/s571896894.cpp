//
// Created by Harshit on 25-08-2020.
//
#include <bits/stdc++.h>
using namespace std;
long long res(vector <int> &,int ,int ,long long ,bool );
const int maxx=3005;
long long dp[maxx][maxx][2];
int main(){
    int n;
    long long x=0,y=0;
    cin>>n;
    vector <int> arr(n);
    for(int i=0;i<maxx;i++){
        for(int j=0;j<maxx;j++){
            dp[i][j][0]=LLONG_MIN;
            dp[i][j][1]=LLONG_MIN;
    }
    }
    for(int &x:arr){
        scanf("%d",&x);
        //cout<<x<<" ";
    }
    //cout<<endl;
    for(int j=0;j<n;j++){
        for(int i=n-1;i>-1;i--){
            for(int q:{0,1}){
                if(i>j){
                    dp[i][j][q]=0;
                    continue;
                }
                if(i==j){
                    if(q==0){
                        dp[i][j][q]=arr[i];
                    }
                    else{
                        dp[i][j][q]=(-1)*arr[i];
                    }
                    continue;
                }
                if(q==0){
                    dp[i][j][q]=max(dp[i+1][j][1-q]+(long long)arr[i],dp[i][j-1][1-q]+(long long)arr[j]);
                }
                else{
                    dp[i][j][q]=min(dp[i+1][j][1-q]-(long long)arr[i],dp[i][j-1][1-q]-(long long)arr[j]);
                }
            }
        }
    }
    cout<<dp[0][n-1][0]<<endl;
}
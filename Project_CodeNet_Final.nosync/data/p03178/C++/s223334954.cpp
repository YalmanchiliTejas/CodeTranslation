#include <bits/stdc++.h>
using namespace std;
int d,dp[100001][101][2];
string k;

int add(int &a , int b){
    a += b;
    if(a >= 1000000007){
        a -= 1000000007;
    }
    return a;
}

int ans(int curr , int mod , int tag){
    if(curr == k.size()){
        if(mod == 0){
            return 1;
        }
        return 0;
    }
    if(dp[curr][mod][tag] != -1){
        return dp[curr][mod][tag];
    }
    int ret = 0;
    if(tag){
        for(int i = 0 ; i < k[curr]-'0' ; i += 1){
            int v = (mod+i)%d;
            add(ret,ans(curr+1,v,1-tag));
        }
        int v = mod+(k[curr]-'0');
        v %= d;
        add(ret,ans(curr+1,v,tag));
    }else{
        for(int i = 0 ; i <= 9 ; i += 1){
            int v = (mod+i)%d;
            add(ret,ans(curr+1,v,tag));
        }
    }
    return dp[curr][mod][tag] = ret;
}

int main(){
    memset(dp,-1,sizeof dp);
    cin >> k >> d;
    int ret = (ans(0,0,1)-1)%1000000007;
    if(ret < 0){
        ret += 1000000007;
    }
    cout << ret << endl;
}
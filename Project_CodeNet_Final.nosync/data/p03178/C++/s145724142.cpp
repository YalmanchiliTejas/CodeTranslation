// Author : Rifayat Samee (Sanzee)
// Problem :
// Algorithm:

/*

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
ll memo[100005][2][101];
int done[100005][2][101],cc=1;

ll dp(int i,int issmall,int rem,const int &d,const string &S,const int &len){
    if(i == len){
        if(rem == 0)
            return 1;
        return 0;
    }
    if(done[i][issmall][rem] == cc)
        return memo[i][issmall][rem];
    ll res = 0;
    int r = S[i] - '0';
    if(issmall){

        for(int j = 0;j<=9;j++){
            if(j >0 && i == 0) continue;
            res = (res + dp(i+1,issmall,(rem+j)%d,d,S,len) )%mod;
        }
    }
    else{
        for(int j = 0;j<r;j++){
            if(j == 0 && i == 0) continue;
            res = (res + dp(i+1,1,(rem+j)%d,d,S,len) )%mod;
        }
        res = (res + dp(i+1,0,(rem+r)%d,d,S,len) )%mod;
    }


    memo[i][issmall][rem] = res;
    done[i][issmall][rem] = cc;
    return res;
}

int main(){

	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
    string S;
    int d;
    cin >> S;
    scanf("%d",&d);
    ll res = (dp(0,0,0,d,S,S.size()) + dp(0,1,0,d,S,S.size()) -1 + mod)%mod;
    printf("%lld\n",res);
	return 0;
}

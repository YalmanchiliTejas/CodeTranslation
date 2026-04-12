#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxx = 1e5+1;
const ll mod = 1e9 + 7;
int dp[maxx][101][2];
string s;
int d;
int Size;
int rec(int pos,int remainder,int exceeds,int number){
		if(pos==Size){
			if(remainder==0){
			 //cout << number << "\n";
			 return 1;
		  }
		  return 0;
		}
		if(dp[pos][remainder][exceeds]!=-1)	return dp[pos][remainder][exceeds];
		int ans = 0;
		if(pos==0){
			for(int i = 0;i <=(int)(s[pos]-48);i ++){ // is pos is 0 then iterate upto s[pos] only .
				ans = ans + rec(pos+1,(remainder+i)%d,((int)(s[pos]-48))==i,number*10+i);
				if(ans>=mod)
					ans-=mod;
			}
		}else{
			for(int i = 0 ;i <=9 ; i ++){
				if(exceeds){ // if prev limit is reached then iterate upto current's limit .
				if(i<=((int)(s[pos] - 48))){
				    ans = ans + rec(pos+1,(remainder + i)%d,((int)(s[pos]-48)==i),number*10+i);
				    if(ans>=mod)
					 ans-=mod;
					}
				}
				else{ // else iterate all digits from 0 to 9.
					 ans = ans + rec(pos+1,(remainder + i)%d,0,number*10+i);
				   if(ans>=mod)
					ans-=mod;
				}
			}
		}
		return  dp[pos][remainder][exceeds]=ans; // memoization
}



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> s;
	cin >> d;
	Size = s.size();
	memset(dp,-1,sizeof dp);
	cout << (rec(0,0,0,0) - 1 + mod)%mod  << "\n";
}

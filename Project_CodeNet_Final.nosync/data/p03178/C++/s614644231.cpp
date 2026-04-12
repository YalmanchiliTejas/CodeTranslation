#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

string s;
int d;

int memo[10005][105][3];

int dp(int idx, int tot, int stat){
   if(idx>=s.size()){
      if(tot == 0) return 1;
      else return 0;
   }
   int &ret = memo[idx][tot][stat];
   if(ret!=-1) return ret;
   ret = 0;
   for(int i=0;i<10;i++){
      if(stat == 0 && i>s[idx]-'0') break;
      if(s[idx]-'0' == i && stat == 0) ret+= dp(idx+1,(tot+i)%d,0);
      else ret+= dp(idx+1,(tot+i)%d,1);
      ret%=MOD;
   }
   return ret;
}

int main(){
   memset(memo,-1,sizeof(memo));
   cin >> s;
   cin >> d;
   int ans = dp(0,0,0);
   printf("%d\n",(ans+MOD-1)%MOD);
	return 0;
}

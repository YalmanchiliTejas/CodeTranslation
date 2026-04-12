#include<bits/stdc++.h>
using namespace std;

const int M=1e9+7;
vector<int>num;
int d;
int dp[100007][110][2];
void add_self(int&a, int b){
     a=a+b;
     if(a>=M)a=a-M;
}
int call(int index, int mod, int flag){

     if(index==num.size()){
          if(mod==0) return 1;
          return 0;
     }
     int&ans=dp[index][mod][flag];
     if(ans!=-1) return ans;

     ans=0;
     int limit;
     if(flag==0){
          limit=num[index];
     }
     else{
          limit=9;
     }

     for(int i=0;i<=limit;i++){
          int nflag=flag;
          int nmod=(mod+i)%d;
          if(flag==0 and i<limit) nflag=1;
          add_self(ans,call(index+1, nmod, nflag));
     }
     return ans;
}


int main(){
     memset(dp, -1, sizeof(dp));
     string s;
     cin>>s;
     cin>>d;

     for(int i=0;i<s.size();i++)num.push_back(s[i]-'0');
     cout<<(call(0, 0, 0)-1+M)%M;
}

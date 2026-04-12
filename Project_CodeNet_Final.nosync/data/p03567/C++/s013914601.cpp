#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
typedef long long LL;
int main(){
   string S;
   cin>>S;
   bool check=false;
   REP(i,S.size()-1){
       if(S[i]=='A'&&S[i+1]=='C'){
          check=true;
       }
   }
   if(check){
      cout<<"Yes"<<endl;
   }else{
      cout<<"No"<<endl;
   }
	return(0);
}
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include <bitset>
#include<math.h>
using namespace std;
#define INF 11000000000
#define MOD 1000000007
typedef long long ll;
typedef pair<ll,int> P;


int main(){
  bool flag=false;
  int N;
  char ans[110000];
  string s;
  cin>>N>>s;

  for(int i=0;i<4;i++){
    if(i==0){
      ans[0]='W'; ans[1]='S';
    }else if(i==1){
      ans[0]='W'; ans[1]='W';      
    }else if(i==2){
      ans[0]='S'; ans[1]='W';            
    }else if(i==3){
      ans[0]='S'; ans[1]='S';                  
    }

    for(int i=1;i<N-1;i++){
      if(s[i]=='o' && ans[i]=='S' || s[i]=='x' && ans[i]=='W'){
        ans[i+1]=ans[i-1];
      }else{
        if(ans[i-1]=='S') ans[i+1]='W';
        else ans[i+1]='S';
      }
    }

    if(s[N-1]=='o' && ans[N-1]=='S' || s[N-1]=='x' && ans[N-1]=='W'){
      if(ans[0]==ans[N-2]) flag=true;
      else flag=false;
    }else{
      if(ans[0]!=ans[N-2]) flag=true;
      else flag=false;
    }

    if(flag){
      if(s[0]=='o' && ans[0]=='S' || s[0]=='x' && ans[0]=='W'){
        if(ans[1]==ans[N-1]) flag=true;
        else flag=false;
      }else{
        if(ans[1]!=ans[N-1]) flag=true;
        else flag=false;
      }
    }

    if(flag){
      for(int i=0;i<N;i++) cout<<ans[i];
      cout<<endl;
      return 0;
    }
  }
  cout<<-1<<endl;
}

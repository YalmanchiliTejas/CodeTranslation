#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define rep(i,n) for(int i=0; i<n; i++)
#define all(x) (x).begin(),(x).end()
#define INF (1e9)

int n;
bool S[100010]={},go,ok1=false,ok2=false;
bool start[4][2]={{1,0},{1,1},{0,0},{0,1}};
string s;
int main(){
  cin >> n >> s;
  rep(i,4){
    //初期設定
    S[0] = start[i][0];
    S[1] = start[i][1];

    for(int j=1; j<=n-2; j++){
      if(s[j]=='o'){
        if(S[j]&&S[j-1])S[j+1]=1;
        if(S[j]&&!S[j-1])S[j+1]=0;
        if(!S[j]&&S[j-1])S[j+1]=0;
        if(!S[j]&&!S[j-1])S[j+1]=1;
      }
      if(s[j]=='x'){
        if(S[j]&&S[j-1])S[j+1]=0;
        if(S[j]&&!S[j-1])S[j+1]=1;
        if(!S[j]&&S[j-1])S[j+1]=1;
        if(!S[j]&&!S[j-1])S[j+1]=0;
      }
    }

    //矛盾しないかどうか判定
    if(s[n-1]=='o'){
      if((S[n-1]==1&&S[0]==S[n-2])||(S[n-1]==0&&S[0]!=S[n-2])){
        ok1 = 1;
      }
    }else{
      if((S[n-1]==1&&S[0]!=S[n-2])||(S[n-1]==0&&S[0]==S[n-2])){
        ok1 = 1;
      }
    }
    if(s[0]=='o'){
      if((S[0]==1&&S[1]==S[n-1])||(S[0]==0&&S[1]!=S[n-1])){
        ok2 = 1;
      }
    }else{
      if((S[0]==1&&S[1]!=S[n-1])||(S[0]==0&&S[1]==S[n-1])){
        ok2 = 1;
      }
    }
    if(ok1&&ok2)break;
    ok1=false;
    ok2=false;
    rep(i,n){
      S[i]=0;
    }
  }
  if(ok1&&ok2){
    rep(i,n){
      if(S[i])cout << "S";
      else cout << "W";
    }
    cout << endl;
  }else{
    cout << -1 << endl;
  }
}
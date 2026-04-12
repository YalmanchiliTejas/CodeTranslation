#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  string s;
  while(1){
    cin >> s;
    if(s=="#") return 0;
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    vector<vector<int>> field(10,vector<int>(10,0));
    int x=0,y=0;
    for(int now=0;now<s.length();now++){
      if(s[now]=='/'){
        y++;
        x=0;
      }else if(s[now]=='b'){
        field[y][x]=2;
        x++;
      }else{
        for(int i=0;i<s[now]-'0';i++){
          field[y][x+i]=1;
        }
        x+=s[now]-'0';
      }
    }
    field[a-1][b-1]=1;
    field[c-1][d-1]=2;
    // for(int i=0;i<9;i++){
    //   for(int j=0;j<9;j++){
    //     cout << field[i][j];
    //   }
    //   cout << endl;
    // }
    int count=0;
    for(int i=0;i<10;i++){
      if(field[i][0]==0){
        cout << endl;
        break;
      }
      for(int j=0;j<10;j++){
        if(field[i][j]==0){
          if(count>0) cout << (count);
          count=0;
          if(field[i+1][0]!=0) cout << "/";
          break;
        }else if(field[i][j]==1){
          count++;
        }else{
          if(count>0) cout << (count);
          count=0;
          cout << "b";
        }
      }
    }
  }
  return 0;
}


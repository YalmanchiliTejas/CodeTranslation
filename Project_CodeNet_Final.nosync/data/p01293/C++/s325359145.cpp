#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string jk,cd[4][13];
int check(char ld,string str){
  char num=str[0],s=str[1];
  int flg = 0;
  if(s==ld) flg = 100;
  if(s==jk[0])flg = 1000;
  if('0'<=num &&num<='9') return num-'0'+flg;
  if(num=='T') return 10+flg;
  if(num=='J') return 11+flg;
  if(num=='Q') return 12+flg;
  if(num=='K') return 13+flg;
  if(num=='A') return 14+flg;
  return 0;
}

int main() {
  while(1){
    cin >> jk;
    if(jk=="#")break;
    for(int i=0;i<4;i++)
      for(int j=0;j<13;j++) cin >> cd[i][j];

    int ld=0,cnt[4]={};
    for(int i=0;i<13;i++) {
      char t = cd[ld][i][1];
      int N=check(t,cd[0][i]);
      int E=check(t,cd[1][i]);
      int S=check(t,cd[2][i]);
      int W=check(t,cd[3][i]);
      pair <int,int> D[4];
      D[0]=make_pair(N,0);
      D[1]=make_pair(E,1);
      D[2]=make_pair(S,2);
      D[3]=make_pair(W,3);
      sort(D,D+4);
      cnt[D[3].second]++;
      ld = D[3].second;
    }
    if(cnt[0]+cnt[2]>cnt[1]+cnt[3]) cout <<"NS "<<cnt[0]+cnt[2]-6<<endl;
    else cout <<"EW "<<cnt[1]+cnt[3]-6<<endl;
  }
  return 0;
}
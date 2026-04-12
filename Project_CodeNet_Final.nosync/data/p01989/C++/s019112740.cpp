#include <bits/stdc++.h>
using namespace std;


#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);i++)

char s[25];
int n;

bool ok(int a, int x){
  if(x<10)return a==1;
  if(x<100)return a==2;
  return a==3;
}

int main(){
  scanf("%s",s);
  n = strlen(s);
  int ans = 0;
  FOR(a,1,4)FOR(b,1,4)FOR(c,1,4)FOR(d,1,4){
    if(a+b+c+d!=n)continue;
    int it = 0;
    int x = 0;
    x=0;REP(i,a){x*=10;x+=s[it++]-'0';}
    if(!ok(a,x))continue;
    if(x>255)continue;

    x=0;REP(i,b){x*=10;x+=s[it++]-'0';}
    if(!ok(b,x))continue;
    if(x>255)continue;

    x=0;REP(i,c){x*=10;x+=s[it++]-'0';}
    if(!ok(c,x))continue;
    if(x>255)continue;

    x=0;REP(i,d){x*=10;x+=s[it++]-'0';}
    if(!ok(d,x))continue;
    if(x>255)continue;

    ans++;
  }
  printf("%d\n",ans);
  return 0;
}

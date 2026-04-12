#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
#include<set>
#include<map>
#include<iostream>
using namespace std;
#define rep(i,n) for(int i=0;i<((int)(n));i++)
#define reg(i,a,b) for(int i=((int)(a));i<=((int)(b));i++)
#define irep(i,n) for(int i=((int)(n))-1;i>=0;i--)
#define ireg(i,a,b) for(int i=((int)(b));i>=((int)(a));i--)
typedef long long int lli;
typedef pair<int,int> mp;

char rigHT[11]={'y','h','n','u','j','m','i','k','o','l','p'};
int main(){
  char a[40];
  while(1){
    fill(a,a+40,0);
    scanf("%s",a);
    if(a[0]=='#') break;

    int len = strlen(a);
    int res=0;
    int te=0;
    rep(i,11){
      if(rigHT[i]==a[0]) te=1;
    }
    reg(i,1,len-1){
      bool mama=true;
      rep(j,11){
        if(a[i]==rigHT[j]){mama=false; break;}
      }
      if(te==1 && !mama) continue;
      else if(te==1 && mama){res++; te=0;}
      else if(te==0 && mama) continue;
      else if(te==0 && !mama){ res++ ; te=1;}
    }
    printf("%d\n",res);
  }

  return 0;

}
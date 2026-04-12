#include <bits/stdc++.h>
using namespace std;
char g;
char f[4][13],a,pp;
int v[4][13],tt[100];
main(){
  tt['T']=10;tt['J']=11;tt['Q']=12;tt['K']=13;tt['A']=14;
  while(scanf("%c%c",&g,&pp),g!='#'){
    for(int i=0;i<4;i++)
      for(int j=0;j<13;j++){
          scanf("%c%c%c",&a,&f[i][j],&pp);
          if(a>='0'&&a<='9')v[i][j]=a-'0';
          else v[i][j]=tt[(int)a];
        }
    int lead=0,score[2]={};
    for(int i=0;i<13;i++){
      int w=-1,ws=-1;
      for(int j=0;j<4;j++){
        int sc=v[j][i];
        if(f[j][i]==g)sc+=100;
        if(f[j][i]!=g&&f[j][i]!=f[lead][i])continue;
        if(sc>ws)ws=sc,w=j;
      }
      lead=w;
      score[w%2]++;
    }
  if(score[0]>score[1])cout<<"NS "<<score[0]-6<<endl;
  else cout<<"EW "<<score[1]-6<<endl;
  }
}
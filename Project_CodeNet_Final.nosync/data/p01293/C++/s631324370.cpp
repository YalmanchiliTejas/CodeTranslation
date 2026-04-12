#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;

char N;
string str;
P t[4][13];
int sum[2];
int change(char ch){
  int a;
  if(ch=='S')a=0;
  else if(ch=='H')a=1;
  else if(ch=='D')a=2;
  else if(ch=='C')a=3;
  return a;
}
int change2(char ch){
  int b;
  if(ch=='T')b=10;
  else if(ch=='J')b=11;
  else if(ch=='Q')b=12;
  else if(ch=='K')b=13;
  else if(ch=='A')b=14;
  else b=ch-'0';
  return b;
}

int main(){
  while(1){
    cin>>N;
    if(N=='#')break;
    for(int i=0;i<4;i++){
      for(int j=0;j<13;j++){
	cin>>str;
	t[i][j].first=change(str[1]);
	t[i][j].second=change2(str[0]);
      }
    }
    sum[0]=sum[1]=0;
    int id=0;
    
    for(int i=0;i<13;i++){

      int rank[4]={};
      rank[change(N)]=3;
      rank[t[id][i].first]=2;
      P maxm=P(0,0);
      for(int j=0;j<4;j++){
	P p=t[j][i];
	p.first=rank[p.first]*100+p.second;
	p.second=j;
	maxm=max(maxm,p);
      }
      sum[maxm.second%2]++;
      id=maxm.second;
    }
    
    if(sum[0]>sum[1])cout<<"NS"<<' '<<sum[0]-6<<endl;
    else cout<<"EW"<<' '<<sum[1]-6<<endl;
  }
  return 0;
}
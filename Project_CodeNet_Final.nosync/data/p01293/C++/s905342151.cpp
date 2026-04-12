#include<iostream>
#include<string>
using namespace std;

int M(char a)
{
  if(a=='T')return 10;
  if(a=='J')return 11;
  if(a=='Q')return 12;
  if(a=='K')return 13;
  if(a=='A')return 14;
  return (a-'2');
}
int main()
{
  string s;
  int Card_N[4][13];
  char Card_S[4][13],Trump;

  while(1){
    cin>>Trump;
    if(Trump=='#')break;
    for(int k=0;k<4;k++){
      for(int i=0;i<13;i++){
	cin>>s;
	Card_N[k][i]=M(s[0]);
	Card_S[k][i]=s[1];
	if(Card_S[k][i]==Trump)Card_N[k][i]+=20;
      }
    }

    int start=0,NS=0,EW=0;
    for(int i=0;i<13;i++){
      int ma=Card_N[start][i],b=start;
      for(int j=1;j<4;j++){
	int a=((b+j)%4);
	if(Card_S[a][i]==Card_S[b][i] || Card_S[a][i]==Trump){
	  if(Card_N[a][i]>ma){
	    ma=Card_N[a][i];
	    start=a;
	  }
	}
      }
      if(start%2==0)NS++;
      else EW++;
    }/*
    for(int i=0;i<4;i++){
      for(int j=0;j<13;j++)cout<<Card_N[i][j]<<" ";
      cout<<endl;
    }*/
    if(NS>EW)cout<<"NS "<<NS-6<<endl;
    else cout<<"EW "<<EW-6<<endl;
  } 
  return 0;
}
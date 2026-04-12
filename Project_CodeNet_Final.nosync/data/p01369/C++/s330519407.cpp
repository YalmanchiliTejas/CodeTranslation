#include<iostream>
#include<cstring>
using namespace std;
int judge(int);
char S[100];
char l[16]="qwertasdfgzxcvb";
int main()
{
  int i,sum=0;
  int SS[100];

  while(1){
    cin>>S;
    if(S[0]=='#')break;

    for(int i=0;i<strlen(S);++i){
      SS[i]=judge(i);
    }
    for(int i=0;i<strlen(S)-1;++i){
      if(SS[i]!=SS[i+1]){sum++;
      }
    }
    cout << sum<<endl;
    sum=0;
  }
  return 0;
}

int judge(int ii)
{
  for(int i=0;i<15;++i){
    if(S[ii]==l[i])return 1;
  }
  return 0;
}
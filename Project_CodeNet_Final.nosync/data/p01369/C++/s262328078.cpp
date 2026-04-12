#include<bits/stdc++.h>
using namespace std;
int main(){
  string R="yhnujmikolp";
  string L="qazwsxedcrfvtgb";
  while(true)
  {
    string S;
    int juge[50]={0};
    int jugeL[50]={0};
    int count=0;
    cin>>S;
    if(S=="#")
    {
      break;
    }
    int len=S.size();
    for(int i=0;i<len;i++)
    {
      for(int k=0;k<=10;k++)
      {
        if(S[i]==R[k])
        {
          juge[i]=1;
        }
      }
    }
    for(int h=1;h<len;h++)
    {
      if(juge[h]!=juge[h-1])
      {
        count++;
      }
    }
    cout<<count<<endl;
  }
  return 0;
}


#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  int a,b,c,d;
 
  while(1){
    cin >> s;
    
    if(s=="#")break;

    int size=s.size();
    
    int t[10][10]={};
    
    cin >> a >> b >> c >> d;

    int count=0,num=0,w=0,h=0,ws=0;

    
    for(int i=0;i<size;i++){
      if(s[i]=='b'){
  ws++;
      }else if(s[i]-'0'>=1 && s[i]-'0'<=9){
  ws+=s[i]-'0';
      }else{
  h++;
  w=ws;
  ws=0;
      }
      
    }
    h++;
    
    
    for(int j=0;j<h;j++){
      for(int i=0;i<w;i++){
  if(s[count]=='/'){
    count++;
      }
      if(s[count]=='b'){
        t[j][i]=1;
        count++;
      }else{
    if(s[count]-'0'>=1 && s[count]-'0'<=9){
      num=s[count]-'0';
      for(int k=0;k<num;k++){
        t[j][i+k]=0;
      }
      i+=num-1;
      count++;
    }
      }
      num=0;
      }
    }
    // cout<<endl;
    // for(int j=0;j<2;j++){
      
    //   for(int i=0;i<w;i++){
    //  cout<<t[j][i]<<' ' ;
    //   }
    //   cout<<endl;
    // }


    t[a-1][b-1]=0;
    t[c-1][d-1]=1;
    
    for(int j=0;j<h;j++){

      for(int i=0;i<w;i++){
        if(i==0&&j!=0)cout<<'/';
        if(t[j][i]==0){
          num++;
          if(i==w-1){
          cout<<num;
          num=0;
          }
        }else if(num>0){
          cout<<num;
          num=0;
        }
      if(t[j][i]==1){
        cout<<'b';
      }
      }
  }
    cout<<endl;
  }
  return 0;
}


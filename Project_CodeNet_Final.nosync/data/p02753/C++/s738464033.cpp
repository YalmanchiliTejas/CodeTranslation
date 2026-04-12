#include"iostream"
 
using namespace std;
int judge[2];
int main(){
 string s;
  cin>>s;
  for(int i=0;i<3;i++)
     judge[s[i]-'A']=1;
  bool ans=true;
  for(int i=0;i<2;i++)
     if(judge[i]==0)
         ans=false;
  if(ans)  cout<<"Yes"<<endl;
  else   cout<<"No"<<endl;
  
  return 0;
}
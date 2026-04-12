#include<iostream>
using namespace std;

int main(void)
{
  string s;
  cin>>s;
  int j=1;
  int d=0;
  for(int i=0;i<s.size();i++){
    if(j==s.size())
      break;
    else if(s[i]=='A'&&s[j]=='C'){
      d=1;
    }
    j++;
  }
  if(d==1)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;

}

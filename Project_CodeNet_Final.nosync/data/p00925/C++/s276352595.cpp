#include<iostream>
#include<stack>
#include<cstdlib>
using namespace std;

int main()
{
  string cal;
  int n,M=0,L=0;
  long long l=0,m=0,top;
  stack<int> S;
  cin>>cal>>n;
  S.push((cal[0]-'0'));
  for(int i=1;i<cal.length()-1;i+=2){
    if(cal[i]=='+'){
      S.push((cal[i+1]-'0'));
    }
    if(cal[i]=='*'){
      top=S.top();S.pop();
      S.push(top*(cal[i+1]-'0'));
    }
  }
  while(!S.empty()){
    m+=S.top();
    S.pop();
  }
  if(m==n)M=1;
  l=(cal[0]-'0');
  for(int i=1;i<cal.length();i+=2){
    if(cal[i]=='+'){
      l+=(cal[i+1]-'0');
    }
    if(cal[i]=='*'){
      l*=(cal[i+1]-'0');
    }
  }
  if(l==n)L=1;
  if(L==1 && M==1)cout<<"U"<<endl;
  else if(L==0 && M==1)cout<<"M"<<endl;
  else if(L==1 && M==0)cout<<"L"<<endl;
  else cout<<"I"<<endl;
  return 0;
}
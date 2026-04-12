#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;

int l_to_r(const char exp[])
{
  int sum;
  sum=(exp[0]-'0');
  for(int i=1;i+1<strlen(exp);i+=2){
    if(exp[i]=='*')
      sum*=(exp[i+1]-'0');
    else sum+=(exp[i+1]-'0');
  }
   
  return sum;
}

int mul_fir(char exp[])
{
  int mul,sum=0;
  vector<int> plus;
  mul=(exp[0]-'0');
  for(int i=1;i<strlen(exp);i+=2){
    if(exp[i]=='*')
      mul*=(exp[i+1]-'0');
    else {
      plus.push_back(mul);
      mul=(exp[i+1]-'0');
    }
  }
  for(int i=0;i<plus.size();i++)
    sum+=plus[i];
  
  return sum+mul;
}

int main()
{
  long long int n,ans1,ans2;
  char exp[18];

  scanf("%s", exp);
  cin>>n;
  ans1=l_to_r(exp);
  ans2=mul_fir(exp);
  if(ans1==n&&ans2!=n) cout<<"L"<<endl;
  else if(ans1!=n&&ans2==n) cout<<"M"<<endl;
  else if(ans1==n&&ans2==n) cout<<"U"<<endl;
  else cout<<"I"<<endl;
}

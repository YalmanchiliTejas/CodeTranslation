#include<bits/stdc++.h>
using namespace std;
typedef int64_t LL;
LL com(LL m,LL j)
{
  switch(j)
  {
    case 1:return m;
    case 2:return m*(m-1)/2;
    case 3:return m*(m-1)*(m-2)/6;
    default:return 0;
  }
}
string S;
int N,K;
LL f(int i,int k,int under)
{
  if(k==0)return 1;
  if(i==N)return 0;
  if(under)return com(N-i,k)*pow(9,k);
  else
  {
    if(S.at(i)=='0')return f(i+1,k,false);
    else return f(i+1,k,true)+f(i+1,k-1,true)*(S.at(i)-'1')+f(i+1,k-1,false);
  }
}
int main()
{
  cin>>S>>K;
  N=S.size();
  cout<<f(0,K,false)<<endl;
}
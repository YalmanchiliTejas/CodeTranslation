#include<bits/stdc++.h>
using namespace std;
int main()
{
  long long a,b,c,m;
  cin>>a>>b>>c;
  m=(a*100)+(b*10)+c;
  if(m%4==0)std::cout << "YES" << '\n';
  else std::cout << "NO" << '\n';

 return 0;

}

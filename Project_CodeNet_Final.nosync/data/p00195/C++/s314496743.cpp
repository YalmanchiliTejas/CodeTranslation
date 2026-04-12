#include<iostream>
using namespace std;

int main()
{
  int s1,s2;
  for(;cin>>s1>>s2,s1||s2;)
    {
      int max=s1+s2;
      char name='A';
      for(int i=1;i<5;i++)
        {
          cin>>s1>>s2;
          if(max<s1+s2)
            {
              max=s1+s2;
              name='A'+i;
            }
        }
      cout<<name<<" "<<max<<endl;
    }
}
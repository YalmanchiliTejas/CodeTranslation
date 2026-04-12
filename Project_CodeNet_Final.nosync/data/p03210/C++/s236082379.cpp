#include<iostream>

using namespace std;
int main()
{
    int y;
    cin>>y;
    if(1<=y<=9)
    {
      if(y==5 or y==3 or y==7 )
      {
          cout<<"YES";
      }
      else
      {
          cout<<"NO";
      }
    }
    return 0;
}
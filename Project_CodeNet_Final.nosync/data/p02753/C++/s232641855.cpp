#include <iostream>
#include <ctype.h>
#include <string>
using namespace std;

int main()
{
  char arr[3];
  int i;
  int count = 1;
  for(i=0; i<3; i++)
    cin>>arr[i];
  for(i=0; i<3; i++)
  {
    if(arr[i] == arr[i+1])
    {
      count++;
    }
  }
  if(count==3)
    cout<<"No"<<"\n";
  else
    cout<<"Yes"<<"\n";
    return 0;
}
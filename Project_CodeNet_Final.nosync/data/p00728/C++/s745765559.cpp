#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
  int a,b[100];
  while(1)
  {
    scanf("%d",&a );
    if(a == 0)
    {
      break;
    }

    for(int i=0; i<a; i++)
    {
      scanf("%d",&b[i] );
    }

    sort(b,b+a);

    int c = 0;
    for(int i=1; i < a-1; i++)
    {
      c+=b[i];
    }
    printf("%d\n",c / (a-2) );
  }
}


#include <iostream>
#include <fstream>
using namespace std;

int a,b,c;
int main()
{
   
    scanf("%d %d %d",&a,&b,&c);
    if ((b*10+c) % 4==0)
    {
        printf("YES");
    } else {printf("NO");}
}

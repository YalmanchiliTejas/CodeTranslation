#include<iostream>
using namespace std;

int main()
{
    char s[3];
    int n=3;
    int con_A=0,con_B=0;
    for(int i=0;i<n;i++)
    {
        scanf("%c",&s[i]);
        if(s[i]=='A')
        {
            con_A++;
        }
        else
        {
            con_B++;
        }
    }
    if(con_A==0||con_B==0)
    {
        printf("No\n");
    }
    else
    {
        printf("Yes\n");
    }
    
    
    return 0;
}

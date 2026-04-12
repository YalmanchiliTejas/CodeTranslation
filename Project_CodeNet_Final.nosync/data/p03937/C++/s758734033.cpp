#include<iostream>
using namespace std;
int main()

{
    int h,w;
    char a[10][10];
    cin>>h>>w;
    int sum=0;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            cin>>a[i][j];
            if(a[i][j]=='#')
                sum++;
        }
    }
    int i=0,j=0;
    while(1)
        {
           if(a[i][j]=='#')
             {
                  i++;
              if(a[i][j]!='#')
                 i--,j++;
             }
            else
            {
                 j--;
                 break;
            }

        }
    if(sum==w+h-1&&i==h-1&&j==w-1)
        cout<<"Possible"<<endl;
    else
        cout<<"Impossible"<<endl;
    return 0;
}

#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int  x,y=0,n;
    cin>> n;
    x=n*800;



    for(int i=15;i<=n;++i){
        if (i%15==0)
        y+=200;
        else
        continue;
    }

    cout <<x-y;
}
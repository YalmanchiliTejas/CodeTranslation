#include <iostream>

using namespace std;

int main()
{
    int h,w,i,j,ok=1;
    char a[8][8];

    cin>>h>>w;

    for(i=1;i<=h;i++)
        for(j=1;j<=w;j++)
            cin>>a[i][j];

    a[h+1][w]='#';

    i=1;
    j=1;

    while(i<=h && j<=w){
            if(a[i][j]=='#' && a[i][j+1]=='#'){
                a[i][j]='.';
                j++;
            }

            else if(a[i][j]=='#' && a[i+1][j]=='#'){
                a[i][j]='.';
                i++;
            }

            else
                break;
    }


    for(i=1;i<=h;i++){
        for(j=1;j<=w;j++){
            if(a[i][j]=='#'){
                ok=0;
                break;
            }
        }
    }

    if(ok==1)
        cout<<"Possible";
    else
        cout<<"Impossible";

    return 0;
}

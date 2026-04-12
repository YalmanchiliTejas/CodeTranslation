#include <iostream>

using namespace std;
int h,w,book[105],book2[105];
int main()
{
    int m=0;
    cin >>h>>w;
    char a[105][105];
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin >>a[i][j];
        }
    }

    for(int i=1;i<=h;i++){
            int n=0;
        for(int j=1;j<=w;j++){
            if(a[i][j]=='.')
                n++;
        }
        if(n==w){
            book[i]=1;
        }
    }
     for(int i=1;i<=w;i++){
            int n=0;
        for(int j=1;j<=h;j++){
            if(a[j][i]=='.')
                    n++;
        }
        if(n==h){
            book2[i]=1;
        }
    }
    for(int k=1;k<=h;k++){
            int i=0;
        for(int j = 1;j<=w;j++){
                if(book[k]==1||book2[j]==1)
                    continue;
                    i=1;
                    cout<<a[k][j];

            }
            if(i==1)
        cout<<endl;
    }

    return 0;
}
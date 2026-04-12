#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n,n){
        int mas[15][15]={},x=n/2,y=x+1;
        mas[y][x]=1;
        for(int i=2;i<=n*n;i++){
            x+=1;y+=1;
            while(1){
                if(y==n)y=0;
                else if(x==n)x=0;
                else if(x<0)x=n-1;
                else if(mas[y][x]!=0){
                    y+=1;x-=1;
                }
                else {
                    mas[y][x]=i;
                    break;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)cout<<setw(4)<<mas[i][j];
            cout<<endl;
        }
    }
}
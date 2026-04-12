#include<iostream>
using namespace std;
int main(){
    int h,w,f,l;
    cin>>h>>w;
    char a[h][w+1];
    for(int i = 0; i < h; i++)cin>>a[i];

    for(int i = 0; i < h-1; f=0,l=0,i++)
    {
        for(int j = 0; j <w; j++)if(a[i+1][j]=='#'){f=j;break;}
        for(int j = w-1; j >=0; j--)if(a[i][j]=='#'){l=j;break;}
        if(f<l){cout<<"Impossible"<<endl;return 0;}
    }
    cout<<"Possible"<<endl;
    return 0;
}
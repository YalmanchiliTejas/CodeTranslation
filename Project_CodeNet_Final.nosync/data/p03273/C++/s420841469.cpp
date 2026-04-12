//abc107b.cpp
#include<bits/stdc++.h>
using namespace std;
int main(){
    int h,w;
    cin>>h>>w;
    char a[h][w];
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            cin>>a[i][j];
        }
    }
    //yoko
    int flag,ryaku[h];
    for(int k=0;k<h;k++)
    {
        ryaku[k]=0;
    }
    for(int c=0;c<h;c++)
    {
        flag=0;
        for(int b=0;b<w;b++)
        {
            if(a[c][b]=='.')
            {
                flag++;
            }
        }
        if(flag==w)
        {
            ryaku[c]=1;            
        }
    }
    int hata,habuki[w];
    for(int g=0;g<w;g++)
    {
        habuki[g]=0;
    }
    for(int d=0;d<w;d++)
    {
        hata=0;
        for(int e=0;e<h;e++)
        {
            if(a[e][d]=='.')
            {
                hata++;
            }
            if(hata==h)
            {
                habuki[d]=1;
            }
        }
    }
    //write
    for(int p=0;p<h;p++)
    {
        for(int q=0;q<w;q++)
        {
            if((ryaku[p]==0)&&(habuki[q]==0))
            {
                cout<<a[p][q];
            }
        }
        if(ryaku[p]==0)
        cout<<endl;
    }
    return 0;
}
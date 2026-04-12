#include<bits/stdc++.h>
using namespace std;
int main(){
    int h=0,w=0;
    cin>>h>>w;
    char a[h][w];
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++)
        cin>>a[i][j];
    map<int ,int > r,c;
    int f=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++)
        {
            if(a[i][j]!='.')
                {
                    f=1;
                    break;}
        }
        if(f==1){
            f=0;
        }
        else
            r[i]=1;
    }
    f=0;
    for(int i=0;i<w;i++){
        for(int j=0;j<h;j++)
        {
            if(a[j][i]!='.')
                {
                    f=1;
                    break;}
        }
        if(f==1){
            f=0;
        }
        else
            c[i]=1;
    }
    for(int i=0;i<h;i++)
    {
        if(r[i]==1)continue;
        for(int j=0;j<w;j++)
        {
            if(c[j]==1)continue;
            else
            cout<<a[i][j];
        }
        cout<<endl;
    }
}

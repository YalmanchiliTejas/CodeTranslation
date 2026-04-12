#include <bits/stdc++.h>
using namespace std;
int h,w;
char room[101][101];
int book1[101],book2[101];
int main()
{
    cin>>h>>w;
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++)
            cin>>room[i][j];
    memset(book1,0,sizeof(book1));
    memset(book1,0,sizeof(book1));
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(room[i][j]=='#'){
                book1[i]=1;
                break;
            }
        }
    }
    for(int i=0;i<w;i++){
        for(int j=0;j<h;j++){
            if(room[j][i]=='#'){
                book2[i]=1;
                break;
            }
        }
    }
    for(int i=0;i<h;i++){
            bool f=false;
        for(int j=0;j<w;j++){
            if(book1[i]==1&&book2[j]==1){
                cout<<room[i][j];
                f=true;
            }
        }
        if(f)
        cout<<endl;
    }
    return 0;
}
#include<cstdio>
#include<iostream>
using namespace std;
int h,w,fir[10],las[10];
bool ans=1;
char a[10][10];
int main() {
    cin>>h>>w;
    for(int i=1;i<=h;i++) {
        scanf("%s",a[i]+1);
        int num=0;
        for(int j=1;j<=w;j++) {
            if(a[i][j]=='#'&&a[i][j+1]!='#')
                num++,las[i]=j;
            if(!fir[i]&&a[i][j]=='#')
                fir[i]=j;
        }
        if(num!=1) ans=0;
        if(fir[i]!=las[i-1]&&i>1) ans=0;
    }
    if(a[h][w]!='#') ans=0; 
    ans ? cout<<"Possible\n":cout<<"Impossible\n";
    return 0;
}

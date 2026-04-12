#include <iostream>
#include <cstdio>
using namespace std;
char a[101][101];
int fm[101];
int fn[101];
void init()
{
    for(int i=0;i<101;i++){
        fm[i]=1;
        fn[i]=1;
    }
}
int main()
{
    int m,n;
    init();
    cin>>m>>n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    int flagm=1;
    int flagn=1;
    int indexm=-1;
    int indexn=-1;
    for(int i=0;i<m;i++){
        flagm=1;
        for(int j=0;j<n;j++){
            if(a[i][j]=='#'){
                flagm=0;
            }
        }
        if(flagm>0){
            fm[i]=0;
        }
    }
    for(int i=0;i<n;i++){
        flagn=1;
        for(int j=0;j<m;j++){
            if(a[j][i]=='#'){
                flagn=0;
            }
        }
        if(flagn>0){
            fn[i]=0;
        }
    }
    for(int i=0;i<m;i++){
        if(fm[i]){
            for(int j=0;j<n;j++){
                if(fn[j])
                    cout<<a[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}

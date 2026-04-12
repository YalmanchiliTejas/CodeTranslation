#include <iostream>
using namespace std;
int h,w,x[110],y[110];
char a[110][110];
int main(){
    cin>>h>>w;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>a[i][j];
            if(a[i][j]=='#'){
                x[i]=1; y[j]=1;
            }
        }
    }
    for(int i=0;i<h;i++){
        if(x[i]==0) continue;
        for(int j=0;j<w;j++){
            if(y[j]==0) continue;
            cout<<a[i][j];
        }
        cout<<endl;
    }
}
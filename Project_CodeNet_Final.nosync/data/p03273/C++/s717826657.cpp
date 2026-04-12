#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

char a[105][105];
int t[105],y[105];

int main(void){
    int h,w;cin>>h>>w;
    //int h2=h,w2=w;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>a[i][j];
            if(a[i][j]=='.'){
                y[i]++;t[j]++;
            }
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(y[i]==w||t[j]==h){
                continue;
            }else{
                cout<<a[i][j];
            }
        }
        if(y[i]!=w)cout<<endl;
    }
    cout<<endl;
    /*
    for(int i=0;i<h;i++){
        cout<<y[i]<<endl;
    }
    
    for(int i=0;i<w;i++){
        cout<<t[i]<<endl;
    }
    */
    
    return 0;
}

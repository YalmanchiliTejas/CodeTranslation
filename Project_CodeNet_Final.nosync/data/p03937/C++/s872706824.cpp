#include <iostream>
using namespace std;
int main(void){
    int h,w;
    cin>>h>>w;
    
    string a[h];
    for (int i = 0;i<h;i++){
        cin>>a[i];
    }
    int pre=0;
    int r,l;
    for (int i=0;i<h;i++){
        r=0;l=-1;
        for (int j=0;j<w;j++){
            if (a[i][j]=='#'){
                r=j;
                if (l==-1){
                    l=j;
                }
            }
        }
        if (i>0 & pre>l){
            cout<<"Impossible";
            exit(0);
        }
        pre=r;
    }
    cout<<"Possible";
    
}

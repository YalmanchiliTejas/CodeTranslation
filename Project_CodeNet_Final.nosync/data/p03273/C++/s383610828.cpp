#include <iostream>
#include <string>
using namespace std;

int main(){
    int H,W,cnti=0,cntj=0;
    cin>>H>>W;
    char c[H*W];
    int a[H],b[W];
    for(int i=0;i<H*W;i++){
        cin>>c[i];
    }
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(c[W*i+j]=='#'){
                a[cnti]=i;
                cnti++;
                break;
            }
        }
    }
    cout<<"\n";
    for(int j=0;j<W;j++){
        for(int i=0;i<H;i++){
            if(c[W*i+j]=='#'){
                b[cntj]=j;
                cntj++;
                break;
            }
        }
    }
    for(int i=0;i<cnti;i++){
        for(int j=0;j<cntj;j++){
            cout<<c[W*a[i]+b[j]];
        }
        cout<<endl;
    }
}

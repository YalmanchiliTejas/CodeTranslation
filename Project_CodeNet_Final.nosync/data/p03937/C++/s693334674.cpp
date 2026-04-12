#include <iostream>
using namespace std;
int h,w;
char a;
int main(){
    cin>>h>>w;
    int x=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>a;
            if(a=='#') x++;
        }
    }
    if(x==h+w-1) cout<<"Possible";
    else cout<<"Impossible";
}
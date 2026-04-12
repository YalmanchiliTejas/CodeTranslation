#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int h,w,cnt=0; cin>>h >>w;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            char a; cin>>a;
            if(a=='#')cnt++;
        }
    }
    if(cnt==h+w-1){
        cout<<"Possible"<<endl;
    }else{
        cout<<"Impossible"<<endl;
    }
    return 0;
}
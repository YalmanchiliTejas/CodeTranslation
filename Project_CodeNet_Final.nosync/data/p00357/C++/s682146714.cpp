#include <bits//stdc++.h>
using namespace std;
int main(void){
    int a,b,i,j;
    cin>>a;
    int jump[a];
    for(i=0;i<a;i++){
        cin>>b;
        jump[i]=b/10;
    }
    int c=0;
    for(i=0;i<a;i++){
        c++;
        if(jump[i]<c)
        continue;
        else
        c=0;
    }
    if(c==0){
        for(i=a-1;0<=i;i--){
            c++;
        if(jump[i]<c)
        continue;
        else
        c=0;
    }
    }
    if(c)
    cout<<"no"<<endl;
    else
    cout<<"yes"<<endl;
    
}



#include <iostream>
#include<string>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    int a[5],b[5],c[5],i,max=0,num=0;
    string str[5]={"A","B","C","D","E"};
    while(cin>>a[0]>>b[0]){
        if(a[0]==0&&b[0]==0)break;
        for(i=1;i<5;i++){
            cin>>a[i]>>b[i];
        }
        for(i=0;i<5;i++){
            c[i]=a[i]+b[i];
        }
        for(i=0;i<5;i++){
            if(max<c[i]){
            max=c[i];
                num=i;
            }
        }
        cout<<str[num]<<" "<<max<<endl;
        max=0;
    }
    return 0;
}
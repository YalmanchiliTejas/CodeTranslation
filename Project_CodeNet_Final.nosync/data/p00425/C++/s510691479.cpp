#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;
int da[6]={1,2,3,4,5,6};
string str;
int main(){
    int n,i;
    int a,b;
    int count=1;
    while(cin>>n){
        if(n==0)break;
        count=1;
        for(i=0;i<n;i++){
            cin>>str;
            if(str=="North"){
                a=da[0];
                da[0]=da[1];
                da[1]=da[5];
                da[5]=da[4];
                da[4]=a;
                count+=da[0];
            }
            else if(str=="East"){
                a=da[0];
                da[0]=da[3];
                da[3]=da[5];
                da[5]=da[2];
                da[2]=a;
                count+=da[0];
            }
            else if(str=="West"){
                a=da[0];
                da[0]=da[2];
                da[2]=da[5];
                da[5]=da[3];
                da[3]=a;
                count+=da[0];
            }
            else if(str=="South"){
                a=da[0];
                da[0]=da[4];
                da[4]=da[5];
                da[5]=da[1];
                da[1]=a;
                count+=da[0];
            }
            else if(str=="Right"){
                b=da[1];
                da[1]=da[2];
                da[2]=da[4];
                da[4]=da[3];
                da[3]=b;
                count+=da[0];
            }
            else if(str=="Left"){
                b=da[1];
                da[1]=da[3];
                da[3]=da[4];
                da[4]=da[2];
                da[2]=b;
                count+=da[0];
            }
        }
        cout<<count<<endl;
        count=1;
        for(i=0;i<6;i++){
        da[i]=i+1;
        }
        
    }
    return 0;
}
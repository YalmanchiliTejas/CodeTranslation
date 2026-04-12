#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
typedef struct{
    string cry;
    int po;
}To;
 
int main(){
    int i,j,n,c=0;
    while(cin>>n&&n){
        if(c)cout<<endl;
        c++;
        To t[n];
        for(i=0;i<n;i++){
            int w,l,d;
            cin>>t[i].cry>>w>>l>>d;
            t[i].po=w*3+d;
        }
        for(i=0;i<n-1;i++){
            for(j=0;j<n-1;j++){
                if(t[j].po<t[j+1].po){
                    To tmp=t[j];
                    t[j]=t[j+1];
                    t[j+1]=tmp;
                }
            }
        }
        for(i=0;i<n;i++){
            cout<<t[i].cry<<","<<t[i].po<<endl;
        }
    }
    return 0;
}

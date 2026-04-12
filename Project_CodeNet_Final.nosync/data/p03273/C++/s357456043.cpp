#include <iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<cctype>
#include<queue>
#include<stack>
#include<stdio.h>
#include<vector>
#include<set>
#include<map>
#include<iomanip>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int main(){

    
    int h,w;
    cin>>h>>w;
    char s[h][w];
    rep(i,h){rep(j,w){cin>>s[i][j];}}
    bool he[h],we[w];
    
    
    
    rep(i,h){
        int a=0;
        rep(j,w){
            if(s[i][j]=='.'){
                a++;
            }
        }
        if(a==w){he[i]=false;
        }else{he[i]=true;}
    }
    
    rep(i,w){
        int a=0;
        rep(j,h){
            if(s[j][i]=='.'){
                a++;
            }
        }
        if(a==h){we[i]=false;
        }else{
            we[i]=true;
        }
    }

    
    
     rep(i,h){
         bool f=0;
         rep(j,w){
         if(he[i]==true&&we[j]==true){
             cout<<s[i][j];
             f=1;
         }
     }
         if(f==1)cout<<endl;
     }

return 0;
}

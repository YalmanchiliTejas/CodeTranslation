#include <iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<cctype>
#include<queue>
#include<regex>
#include<stack>
#include<stdio.h>
#include<vector>
#include<set>
#include<map>
#include<iomanip>
#define rep(i,n) for(int long long i=0;i<n;i++)
typedef int long long ll;
using namespace std;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool dp[5010][5010];

int main(){
  
    ll n;
    string s;
    cin>>n>>s;
    
    //0S 1W
    bool t=0;
    bool tt=0;
    for(int i=0;i<2;i++){
        t=!t;
        for(int j=0;j<2;j++){
            tt=!tt;
            
            vector<bool> v(n+1);
            v[0]=t;
            v[1]=tt;
            for(int l=1;l<n;l++){
                if(s[l]=='o'){
                    if(v[l]==0){
                        v[l+1]=v[l-1];
                    }else{
                        v[l+1]=!v[l-1];
                    }
                }else if(s[l]=='x'){
                        if(v[l]==0){
                            v[l+1]=!v[l-1];
                        }else{
                            v[l+1]=v[l-1];
                        }
                }
            }
            
            bool flag=0;
            if(v[n]==v[0]){
            if(s[0]=='o'){
                if(v[0]==0){
                    if(v[n-1]==v[1]){flag=1;}
                }else{
                    if(v[n-1]!=v[1]){flag=1;}
                }
            }else if(s[0]=='x'){
                if(v[0]==0){
                    if(v[n-1]!=v[1]){flag=1;}
                }else{
                    if(v[n-1]==v[1]){flag=1;}
                }
            }
            if(flag==1){
                for(int k=0;k<n;k++){
                    if(v[k]==0){cout<<'S';}else{cout<<'W';}
                }cout<<endl;return 0;
            }
        }
        }
        
    }
    
    cout<<-1<<endl;
   
    
 
    
return 0;
}

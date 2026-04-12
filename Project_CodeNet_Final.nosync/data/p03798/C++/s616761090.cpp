#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main() {
    int n;cin>>n;
    string s;cin>>s;
    
    int a[4][n+1];
    
    rep(i,4){
        rep(j,2){
            a[i][j]=0;
        }
    }
    a[0][0]=1,a[0][1]=1,a[1][0]=1,a[2][1]=1;
    
    
    rep(i,4){
        rep(j,n-1){
            if(s[j+1]=='o'){
                if(a[i][j+1]==1)a[i][j+2]=a[i][j];
                else a[i][j+2] = 1 - a[i][j];
            }
            else{
                if(a[i][j+1]==1)a[i][j+2] = 1 - a[i][j];
                else a[i][j+2] = a[i][j];
            }
        }
        if((s[0]=='o' && a[i][0]==1 && a[i][1]==a[i][n-1] )|| (s[0]=='x' && a[i][0]==1 && a[i][1]!=a[i][n-1]) || (s[0]=='o' && a[i][0]==0 && a[i][1]!=a[i][n-1] )|| (s[0]=='x' && a[i][0]==0 && a[i][1]==a[i][n-1])){
            if((s[n-1]=='o' && a[i][n-1]==1 && a[i][0]==a[i][n-2] )|| (s[n-1]=='x' && a[i][n-1]==1 && a[i][0]!=a[i][n-2]) || (s[n-1]=='o' && a[i][n-1]==0 && a[i][0]!=a[i][n-2] )|| (s[n-1]=='x' && a[i][n-1]==0 && a[i][0]==a[i][n-2])){
         rep(j,n){
             if(a[i][j]==1)cout<<'S';
             else cout<<'W';
         }
         cout<<endl;
         return 0;
        }
        }
    }
    
    cout<<-1<<endl;
	return 0;
}
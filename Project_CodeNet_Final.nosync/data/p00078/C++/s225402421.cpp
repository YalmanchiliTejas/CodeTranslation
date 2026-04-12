#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define all(a)  (a).begin(),(a).end()
#define pb push_back
#define INF 999999999

int data[20][20];


int main(){
    int n;
    while(cin>>n){
        if(n==0)break;
        
        rep(i,20)rep(j,20)data[i][j]=0;
        int x,y;
        x=(n-1)/2;
        y=(n-1)/2+1;
        
        int c=1;
        while(1){
//            cout<<x<<" "<<y<<endl;
            if( x<0 ){
                x=n-1;
            }else if(y<0){
                y=n-1;
            }else if(y>=n){
                y=0;
            }else if(x>=n){
                x=0;
            }
            else if( data[x][y]!=0 ){
                x--,y++;
            }
            else{
                data[x][y]=c;
                c++;
                x++,y++;
            }
//            cout<<c<<endl;
            if(c==n*n+1)break;
        }
        rep(i,n){
            rep(j,n){
                printf("%4d",data[j][i]);
            }
            cout<<endl;
        }
   }
}
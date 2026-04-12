#include <bits/stdc++.h>
using namespace std;
#define N_MAX 100000

int main(){
//入力
int a,b,c,x,y;
int ans=-1;

    cin >>a>>b>>c>>x>>y ;

    for(int i=0;i<=max(2*x,2*y);i++){
        if(i%2==0){
            int ae,be;
            ae=max(0,x-i/2);
            be=max(0,y-i/2);
            
            int tmp;
            tmp=a*ae+b*be+c*i;

            if(ans==-1) ans=tmp;
            else ans=min(ans,tmp);
        }
    }
    cout <<ans <<endl;
    return 0;
}
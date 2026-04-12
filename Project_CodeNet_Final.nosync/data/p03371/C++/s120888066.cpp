#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    int ans=0;
    while(x!=0||y!=0){
        if(x!=0&&y!=0){
            int min1=min(a+b,c*2);
            ans+=min1;
            x--; y--;
        }
        else if(x==0&&y!=0){
            int min2=min(b,c*2);
            ans+=min2;
            y--;
        }
        else if(x!=0&&y==0){
            int min3=min(a,c*2);
            ans+=min3;
            x--;
        }
    }
    cout<<ans<<endl;
}
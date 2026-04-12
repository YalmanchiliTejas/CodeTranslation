#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define int long long
#define P pair<long,long>
#define all(a) a.begin(),a.end()
using namespace std;

signed main(){
    int a,b,ab,x,y; cin>>a>>b>>ab>>x>>y;
    if(a+b<=ab*2){
        cout<<a*x+b*y<<endl; return 0;
    }
    if(x>=y){
        if(a<=ab*2){
            cout<<ab*y*2+a*(x-y)<<endl;
            return 0;
        }
        else{
            cout<<ab*x*2<<endl;
            return 0;
        }
    }
    if(x<y){
        if(b<=ab*2){
            cout<<ab*x*2+b*(y-x)<<endl;
            return 0;
        }
        else{
            cout<<ab*y*2<<endl;
            return 0;
        }
    }
}
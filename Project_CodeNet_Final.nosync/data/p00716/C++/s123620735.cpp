#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb emplace_back
typedef long long ll;
typedef pair<int,int> pint;

int main(){
    int m;
    cin>>m;
    int d,y,n;
    int f,c;
    double p;
    while(m--){
        cin>>d>>y>>n;
        int mx=0;
        rep(i,n){
            int td=d;
            cin>>f>>p>>c;
            if(f==0){
                int cnt=0;
                rep(j,y){
                    cnt+=p*td;
                    td-=c;
                }
                td+=cnt;
            }
            else{
                rep(j,y){
                    td=p*td+td;
                    td-=c;
                }
            }
            mx=max(mx,td);
        }
        cout<<mx<<endl;
    }
    return 0;
}

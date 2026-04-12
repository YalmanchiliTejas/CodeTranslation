#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
    int a,b,ab,x,y;
    cin>>a>>b>>ab>>x>>y;
    int apb = a+b;
    if(ab*2>apb){
        int sum = x*a+y*b;
        cout<<sum<<endl;
    }
    else{
        int ans = inf;
        int min1 = min(x,y);
        int sum = ab*min1*2;
        //cout<<sum<<endl;
        //最低min1分はabで買う
        x -= min1;
        y -= min1;
        //cout<<x<<" "<<y<<endl;
        for(int i = 0;i <=x;i++){
            for(int j = 0;j<=y;j++){
                //aをi枚,jをb枚個別で買う
                //cout<<"check"<<i<<" "<<j<<endl;
                int copy = sum;
                copy+=a*i+b*j;
                copy+=ab*2*max(x-i,y-j);
                ans = min(ans,copy);
                //cout<<copy<<" "<<ans<<endl;
                //cout<<endl;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

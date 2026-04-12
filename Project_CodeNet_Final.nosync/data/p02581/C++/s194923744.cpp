#include<bits/stdc++.h>
using namespace std;
using ll=long long;
template<class T,class U> inline bool chmin(T&x,U y){if(x>y){x=y;return true;}return false;}
template<class T,class U> inline bool chmax(T&x,U y){if(x<y){x=y;return true;}return false;}
#define fr(i,n) for(int i=0;i<(n);++i)
#define Fr(i,n) for(int i=1;i<=(n);++i)
#define ifr(i,n) for(int i=(n)-1;i>=0;--i)
#define iFr(i,n) for(int i=(n);i>0;--i)

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,ans{};
    cin>>n;
    if(n==1) return puts("1"),0;
    vector<int> a(3*n);
    for(auto&i:a) cin>>i,--i;
    auto dp=vector(n,vector(n,INT_MIN));
    auto dp2=vector(n,INT_MIN);
    int dp3{};
    fr(i,n) sort(a.begin()+max(0,3*i-1),a.begin()+3*i+2);
    dp[a[0]][a[1]]=dp2[a[0]]=dp2[a[1]]=0;
    struct ud{
        int i,j,k;
    };
    vector<ud> q;
    Fr(i,n-1){
        int x=a[3*i-1],y=a[3*i],z=a[3*i+1];
        if(x==z){
            ++ans;
            continue;
        }
        fr(j,n){
            q.push_back(ud{j,x,dp2[j]});
            q.push_back(ud{j,y,dp2[j]});
            q.push_back(ud{j,z,dp2[j]});
            q.push_back(ud{x,y,max(dp3,dp[z][z]+1)});
            q.push_back(ud{x,z,max(dp3,dp[y][y]+1)});
            q.push_back(ud{y,z,max(dp3,dp[x][x]+1)});
        }
        if(x==y or y==z){
            if(y==z) swap(x,z);
            fr(j,n) if(j!=x){
                q.push_back(ud{j,z,dp[min(j,x)][max(j,x)]+1});
            }
            q.push_back(ud{x,x,dp[z][z]+1});
        }
        for(auto[X,Y,D]:q){
            if(X>Y) swap(X,Y);
            chmax(dp[X][Y],D);
            chmax(dp2[X],D);
            chmax(dp2[Y],D);
            chmax(dp3,D);
        }
        q.clear();
    }
    cout<<max(dp3,dp[a[3*n-1]][a[3*n-1]]+1)+ans<<'\n';
}
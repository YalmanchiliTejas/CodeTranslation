#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#define int long long
constexpr long long INF = numeric_limits<long long>::max() / 2;

using Graph = vector<vector<int>>;

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    
    int N,X,M;
    cin>>N>>X>>M;
    int v[M+1]{};
    rep(i,M+1)v[i]=-1;
    int x=X;
    x%=M;
    int ans=0;
    bool z=false;
    rep(i,N){
        int nv=x*x;
        nv%=M;
        if(v[x]!=-1){
            //x=nv;
            z=true;
            break;
        }
        v[x]=nv;
        x=nv;

    }

    int c=0;
    int nn=x;
    int co=0;
    while(z){
        c++;
        co+=nn;
        nn=v[nn];
        if(nn==x)break;
    }
    //cout<<"-----------------"<<endl;
    //int a=0;
    int y=X%M;
    rep(i,N){
        if(z&&y==nn){
            int o=(N-1-i)/c;
            i+=o*c;
            ans+=o*co;
            if(i>=N-1){
                ans+=y;
                break;
            }
        }
        ans+=y;
        y=v[y];
    }
    cout<<ans<<endl;





}

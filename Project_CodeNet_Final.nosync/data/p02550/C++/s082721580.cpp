#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=(n);i++)
using ll=long long;

int main(){
    ll n,x,m,ans=0,gap,j=0;
    cin>>n>>x>>m;
    //ll k=x;
    queue<ll> que;
    vector<bool> vis(m+10,false);
    bool check=false;
    vis[x]=true;
    que.push(x);
    ans+=x;
    rep(i,n-1){
        x=(x*x)%m;
        que.push(x);
        if(vis[x]){
            gap=x;
            j=i;
            //cout<<i+2<<endl;
            check=true;
            break;
        }
        vis[x]=true;
        ans+=x;
    }
    if(!check){
        cout<<ans<<endl;
        return 0;
    }
    else{
        ans=0;
        ll t=0;
        //ループに入る前
        while(que.front()!=gap){
            ans+=que.front();
            que.pop();
            j--;
            t++;
        }
        //cout<<ans<<endl;
        ll jj=j;
        ll roo=0;
        //ループの中身の合計
        //cout<<endl;
        while(jj){
            jj--;
            //cout<<que.front()<<endl;
            roo+=que.front();
            que.push(que.front());
            que.pop();
        }
        //cout<<roo<<endl;
        //ループの中身（ans）
        n-=t;
        que.pop();
        if(j!=0){
            ans+=roo*(n/j);
            j=n%j;
            for(int i=0;i<j;i++){
                ans+=que.front();
                que.pop();
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
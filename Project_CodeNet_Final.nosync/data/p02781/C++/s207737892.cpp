#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int> 
#define mp make_pair
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fi first
#define se second
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
string n;
int k;
ll ans=0;
int dfs2(vector<int> now){
    int nans=0;
    if(now[0]==1){
        nans=1;
        nans*=n[1]-'0'-1;
        for(int i=0;i<now.size()-1;i++) nans*=9;
        string ha=n;
        for(int i=2;i<=n.size()-1;i++) ha[i]='0';
        if(now.size()==3)
            for(int i=1;i<=9;i++)
                for(int j=1;j<=9;j++){
                    ha[now[1]]=i+'0';
                    ha[now[2]]=j+'0';
                    if(ha<=n) nans++;
                }
        if(now.size()==2)
            for(int i=1;i<=9;i++){
                ha[now[1]]=i+'0';
                if(ha<=n) nans++;
            }
        if(now.size()==1) nans++;
    }
    else{
        nans=1;
        for(int i=0;i<now.size();i++) nans*=9;
    }
    return nans;
}
void dfs(int cnt,vector<int> now){
    if(cnt && now[cnt-1]==n.size()-1 && cnt!=k) return;
    if(cnt==k){
        ans+=dfs2(now);
        return;
    }
    for(int ha=(cnt==0?1:now[cnt-1]+1);ha<=n.size()-1;ha++){
        vector<int> ooo=now;
        ooo.pb(ha);
        dfs(cnt+1,ooo);
    }
}
int main(){
    cin>>n>>k;
    n='$'+n;
    vector<int> o;
    dfs(0,o);
    cout<<ans<<endl;
    return 0;
}
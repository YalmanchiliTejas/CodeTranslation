#include<bits/stdc++.h>
#include<cstdio>
#define ll long long
#define fi first
#define se second
using namespace std;
typedef pair<ll,ll> lp;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
void A() {
    int n;
    cin>>n;
    vector<int> a(n,0);
    for(int i=0; i<n; i++)
        cin>>a[i];
    vector<int> dp(n+1,inf);
    dp[0]=0;
    for(int i=1; i<n; i++) {
        dp[i]=min(dp[i],dp[i-1]+abs(a[i]-a[i-1]));
        if(i>=2)
            dp[i]=min(dp[i],dp[i-2]+abs(a[i]-a[i-2]));
    }
    cout<<dp[n-1]<<endl;

}
void B() {
    int n,k;
    cin>>n>>k;
    vector<int> dp(n+1,inf);
    vector<int> h(n,0);
    for(int i=0; i<n; i++)
        cin>>h[i];
    dp[0]=0;
    for(int i=1; i<n; i++) {
        for(int len=1; len<=min(k+1,i+1); len++) {
            int j=i-len+1;
            dp[i]=min(dp[i],dp[j]+abs(h[j]-h[i]));
        }
    }
    cout<<dp[n-1]<<endl;
}
void C() {
    int n;
    cin>>n;
    vector<vector<int>> a(n,vector<int>(3,0));
    for(int i=0; i<n; i++)
        cin>>a[i][0]>>a[i][1]>>a[i][2];
    vector<vector<int>> dp(n,vector<int>(3,0));
    dp[0][0]=a[0][0];
    dp[0][1]=a[0][1];
    dp[0][2]=a[0][2];
    for(int i=1; i<n; i++) {
        for(int j=0; j<3; j++) {
            for(int k=0; k<3; k++) {
                if(j==k)
                    continue;
                dp[i][j]=max(dp[i][j],dp[i-1][k]+a[i][j]);
                //cout<<dp[i][j]<<endl;
            }
        }
    }
    cout<<max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]))<<endl;
}
void D() {
    ll n,W;
    cin>>n>>W;
    vector<lp> p;
    for(int i=0; i<n; i++) {
        ll a,b;
        cin>>a>>b;
        p.emplace_back(a,b);
    }
    sort(p.begin(),p.end());
    vector<ll> dp(W+1,0);
    for(int i=0; i<n; i++) {
        for(int j=W; j>=p[i].first; j--) {
            if(j>0)
                dp[j]=max(dp[j],dp[j-1]);
            dp[j]=max(dp[j],dp[j-p[i].fi]+p[i].se);
        }
    }
    cout<<dp[W]<<endl;

}
void E() {
    //价值比较小，将dp[i]转化为获得当前i的价值的最小体积，然后根据W寻找符合要求的解；
    int n,W;
    cin>>n>>W;
    vector<ll> w(n,0);
    vector<ll> v(n,0);
    for(int i=0; i<n; i++)
        cin>>w[i]>>v[i];
    vector<ll> dp(100005,inf);
    dp[0]=0;
    int res=0;
    for(int i=0; i<n; i++) {
        for(int j=1e5; j>=v[i]; j--) {
            dp[j]=min(dp[j],dp[j-v[i]]+w[i]);
            if(dp[j]<=W) {
                res=max(res,j);
            }
        }
    }
    cout<<res<<endl;

}
void F() {
    string s,t;
    cin>>s>>t;
    int n=s.size(),m=t.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            char a=s[i-1],b=t[j-1];
            if(a==b) {
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
            }
            dp[i][j]=max(dp[i][j],max(dp[i-1][j],dp[i][j-1]));
        }
    }
    int i=n,j=m;
    stack<char> st;
    while(i!=0&&j!=0) {
        char a=s[i-1],b=t[j-1];
        if(a==b) {
            st.push(a);
            j--;
            i--;
        } else {
            if(dp[i][j]==dp[i-1][j])
                i--;
            else
                j--;
        }
    }
    string res;
    while(!st.empty()) {
        res+=st.top();
        st.pop();
    }
    cout<<res<<endl;
}
int Ghelper(vector<int>& dp,vector<vector<int>>& edge,int cur,int& ans) {
    if(dp[cur]!=-1)
        return dp[cur];
    int res=0;
    for(auto nb:edge[cur]) {
        res=max(res,Ghelper(dp,edge,nb,ans)+1);
    }
    ans=max(ans,res);
    dp[cur]=res;
    return res;
}
void G() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edge(n+1,vector<int>());
    for(int i=0; i<m; i++) {
        int x,y;
        cin>>x>>y;
        edge[x].push_back(y);
    }
    vector<int> dp(n+1,-1);
//    vector<bool> vis(n+1,0);
    int res=0;
    for(int i=1; i<=n; i++) {
//        if(vis[i]) continue;
//        vis[i]=true;
        Ghelper(dp,edge,i,res);
    }
    cout<<res<<endl;
}
void H() {
    int H,W;
    cin>>H>>W;
    vector<vector<char>> grid(H+1,vector<char>(W+1,'.'));
    vector<vector<ll>> dp(H+1,vector<ll>(W+1,0));
    for(int i=1; i<=H; i++) {
        for(int j=1; j<=W; j++) {
            cin>>grid[i][j];
        }
    }
    dp[1][1]=1;
    for(int i=1; i<=H; i++) {
        for(int j=1; j<=W; j++) {
            if(i==1&&j==1)
                continue;
            if(grid[i][j]=='#')
                dp[i][j]=0;
            else {
                dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
            }
        }
    }
    cout<<dp[H][W]<<endl;
}
void I() {
    int n;
    cin>>n;
    vector<vector<double>> dp(n+1,vector<double>(n+1,0.0));
    vector<double> p(n,0.0);
    for(int i=0; i<n; i++)
        cin>>p[i];
    dp[0][0]=1.0;
    for(int i=1; i<=n; i++) {
        for(int j=0; j<=i; j++) {
            if(j>0)
                dp[i][j]+=dp[i-1][j-1]*p[i-1];
            dp[i][j]+=dp[i-1][j]*(1-p[i-1]);
        }
    }
    double res=0.0;
    for(int i=(n+1)/2; i<=n; i++)
        res+=dp[n][i];
    printf("%.10f\n",res);
}
double JHelper(vector<vector<vector<double>>>& dp,int a,int b,int c,int n)
{
    //cout<<a<<" "<<b<<" "<<c<<endl;
    if(a==0&&b==0&&c==0) return 0;
    if(dp[a][b][c]>0) return dp[a][b][c];
    double sum=a+b+c;
    double ans=1.0*n/sum;
    if(a) ans+=JHelper(dp,a-1,b,c,n)*(1.0*a/sum);
    if(b) ans+=JHelper(dp,a+1,b-1,c,n)*(1.0*b/sum);
    if(c) ans+=JHelper(dp,a,b+1,c-1,n)*(1.0*c/sum);
    dp[a][b][c]=ans;
    return ans;
}
void J() {
    int n;
    cin>>n;
    vector<int> a(n,0);
    for(int i=0;i<n; i++)
        cin>>a[i];
    int cnt[4]={0,0,0,0};
    for(int i:a) {
        cnt[i]++;
    }
    //cout<<"OK"<<endl;
    vector<vector<vector<double>>> dp(n+1,vector<vector<double>>(n+1,vector<double>(n+1,-1.0)));
    printf("%.13f\n",JHelper(dp,cnt[1],cnt[2],cnt[3],n));
}
//int KHelper(vector<int>& a,vector<int>& dp,int cur,int n)
//{
//    cout<<cur<<" "<<endl;
//    if(dp[cur]!=-1) return dp[cur];
//    dp[cur]=0;
//    for(int i=0;i<n&&cur>=a[i];i++){
//        dp[cur]|=1-KHelper(a,dp,cur-a[i],n);
//        if(dp[cur]==1) break;
//    }
//    return dp[cur];
//}
void K() {
    int n,k;
    cin>>n>>k;
    vector<int> a(n+1,0);
    vector<int> dp(k+3,-1);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
//    if(KHelper(a,dp,k,n)==1) cout<<"First"<<endl;
//    else cout<<"Second"<<endl;
    dp[0]=0;
    for(int i=1;i<=k;i++){
        dp[i]=0;
        for(int j=0;j<n&&a[j]<=i;j++){
            dp[i]|=1-dp[i-a[j]];
            if(dp[i]==1) break;
        }
    }
    if(dp[k]==1) cout<<"First"<<endl;
    else cout<<"Second"<<endl;
}
void L() {
    int n;
    cin>>n;
    vector<ll> a(n+1,0);
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<vector<ll>> dp(n+2,vector<ll>(n+2,0));
    for(int len=1;len<=n;len++){
        for(int i=1;i+len<=n+1;i++){
            int j=i+len-1;
            if((n-len)%2==0){
                dp[i][j]=max(dp[i+1][j]+a[i],dp[i][j-1]+a[j]);
            }
            else {
                dp[i][j]=min(dp[i+1][j]-a[i],dp[i][j-1]-a[j]);
            }
        }
    }
    cout<<dp[1][n]<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    L();
}

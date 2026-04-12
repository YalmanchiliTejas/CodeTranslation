//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
//#include <atcoder/all>
//using namespace atcoder;
using namespace std;
#define all(v) v.begin(), v.end()
using in = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define yes cout<<"yes"<<endl
#define no cout<<"no"<<endl
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
const double PI=3.14159265358979323846;
 in MOD = 1000000007;
const in INF=1e18+7;
const int inf=1e9+7;
using P=pair<int,int>;
vector<int> dx={0,1,-1,0};
vector<int> dy={1,0,0,-1};


int main(){
ios::sync_with_stdio(false);cin.tie(nullptr);
cout << fixed << setprecision(10);
    in n,x,m;
    cin>>n>>x>>m;
    if(n==1){
        cout<<x%m<<endl;
        return 0;
    }

    vector<int> mod(m,-1);
 
    MOD=m;

    int st=-1,gl=-1;
    in cnt=x%m;
    mod[cnt]=0;
    vector<in> sum(m,0);
    sum[0]=cnt;

    rep(i,m+1){
        if(mod[cnt*cnt%m]>-1){
            st=mod[cnt*cnt%m];
            gl=i;
            break;
        }
        sum[i+1]=(sum[i]+cnt*cnt%m);
        mod[cnt*cnt%m]=mod[cnt]+1;
        cnt=cnt*cnt%m;
    }


    in roop=0;
    if(st>0)roop=sum[gl]-sum[st-1];
    else roop=sum[gl];
    in roop_cnt=gl-st+1;


    if(n<=st){
        cout<<sum[n]<<endl;
        return 0;
    }
    in ans=0;
    if(st>0)ans=sum[st-1];

    n -=st;

    ans += (n/roop_cnt)*roop;
    n %= roop_cnt;
    if(st!=0)ans += sum[n+st-1]-sum[st-1];
    else if(n>0) ans += sum[n-1];

    
    cout<<ans<<endl;
}/*
./problem.exe
*/
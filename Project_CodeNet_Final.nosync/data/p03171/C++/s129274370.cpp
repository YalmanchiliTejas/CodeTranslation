//Exp val.
//https://atcoder.jp/contests/dp/tasks/dp_j
//https://codeforces.com/blog/entry/64250?#comment-523543
#include <bits/stdc++.h>//Carefully Crafted by hetp111
using namespace std;
#define int long long
#define double long double
#define all(v) (v).begin(),(v).end()
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vii vector<pii>
#define MOD (1000000007)
//#define MOD (998244353)
#define PI acos(-1)
#define eps (1e-8)
#define INF (1e18)
#define FASTER ios_base::sync_with_stdio(0);cin.tie(0)
template<class A,class B>ostream&operator<<(ostream&out,const pair<A,B>&a){return out<<"("<<a.first<<","<<a.second<<")";}
template<class A>ostream&operator<<(ostream&out,const vector<A>&a){for(const A &it:a)out<<it<<" ";return out;}
template<class A,class B>istream&operator>>(istream&in,pair<A,B>&a){return in>>a.first>>a.second;}
template<class A>istream&operator>>(istream&in,vector<A>&a){for(A &i:a)in>>i;return in;}
//ifstream cinn("input.txt");ofstream coutt("output.txt");

int n;
int dp[3000][3000];
int v[3000];

int f(int i,int j){
    if(i==j)return v[i];
    int &ans=dp[i][j];
    if(ans!=-1)return ans;
    
    ans=max(v[i]-f(i+1,j),v[j]-f(i,j-1));
    
    return ans;
    
}

signed main(){
    FASTER;
    memset(dp,-1,sizeof dp);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<f(0,n-1);
}

#include <bits/stdc++.h>//Carefully Crafted by hetp111
using namespace std;
#define int long long
#define double long double
#define all(v) (v).begin(),(v).end()
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define vii vector<pii>
#define MOD 1000000007
#define PI 3.14159265359
#define eps (1e-8)
#define FASTER ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
template<class A,class B>ostream&operator<<(ostream&out,const pair<A,B>&a){return out<<"("<<a.first<<","<<a.second<<")";}
template<class A>ostream&operator<<(ostream&out,const vector<A>&a){for(const A &it:a)out<<it<<" ";return out;}
template<class A,class B>istream&operator>>(istream&in,pair<A,B>&a){return in>>a.first>>a.second;}
template<class A>istream&operator>>(istream&in,vector<A>&a){for(A &i:a)in>>i;return in;}
//ifstream cinn("input.txt");ofstream coutt("output.txt");

string k;
int D;
int dp[10000][100][2];

int f(int indx,int sum,int nine){
    if(indx==k.size())return sum==0;
    if(dp[indx][sum][nine]!=-1)return dp[indx][sum][nine];
    int ans=0;
    int e = nine?9:(k[indx]-'0');
    for(int i=0;i<=e;i++){
        ans=(ans+f(indx+1,(sum+i)%D,nine||(i<e)))%MOD;
    }
    return dp[indx][sum][nine]=ans;
}

signed main(){
    FASTER;
    memset(dp,-1,sizeof dp);
    cin>>k>>D;
    cout<<(f(0,0,0)-1+MOD)%MOD;
}
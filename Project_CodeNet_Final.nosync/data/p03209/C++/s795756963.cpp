#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vin=vector<int>;
using vll=vector<long long>;
using vvin=vector<vector<int>>;
using vvll=vector<vector<long long>>;
using vstr=vector<string>;
using vvstr=vector<vector<string>>;
using vch=vector<char>;
using vvch=vector<vector<char>>;
using vbo=vector<bool>;
using vvbo=vector<vector<bool>>;
using vpii=vector<pair<int,int>>;
using pqsin=priority_queue<int,vector<int>,greater<int>>;
#define mp make_pair
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(s);i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define decp(n) cout<<fixed<<setprecision((int)n)
const ll inf=1e9+7;
const ll INF=1e18;

int main(){
    int n;ll x;cin>>n>>x;
    vll burger(n+1),patty(n+1);
    burger[0]=1;patty[0]=1;
    rep(i,n){
        burger[i+1]=2*burger[i]+3;
        patty[i+1]=2*patty[i]+1;
    }
    ll sum=0;
    for(int i=n;i>0;i--){
        if(x==burger[i]){
            sum+=patty[i];
            break;
        }
        else if(x>burger[i-1]+2){
            sum+=patty[i-1]+1;
            x-=burger[i-1]+2;
        }
        else if(x==burger[i-1]+2){
            sum+=patty[i-1]+1;
            break;
        }
        else if(x>1)x--;
        else break;
        if(i==1&&x==1)sum++;
    }
    cout<<sum<<endl;
}
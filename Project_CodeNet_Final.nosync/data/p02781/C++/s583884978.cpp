#include<bits/stdc++.h>
using namespace std;

using ll =  long long;
using pint =  pair<int,int>;

#define rep(i,n) for(int (i)=0,temp=(int)(n);(i)<temp;++(i))
#define repi(i,start,end) for(int (i)=(start),temp=(int)(end);i<(end);++(i))
#define rfor(x,v) for(const auto& (x) : (v))
#define all(x) (x).begin(),(x).end()
#define SORT(v, n) sort((v), (v)+(n))
#define vsort(v) sort((v).begin(), (v).end())
#define vfsort(v,lambda) sort(all((v)),(lambda))
#define vint vector<int>
#define vvint vector<vector<int>> //vvint v(n,vint(n))
#define vin(v) rep(i,(v).size()) {cin >> (v)[i];}
//最終奥義 #define int long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
//lambda: [&](int x, int y){return x<y;}
string n;int k,len;

ll nCr(int n,int r){
    if(r==1)return n;
    if(r==2)return n*(n-1)/2;
    return n*(n-1)*(n-2)/6;
}
ll solve(int i,int k,bool smaller){
    if(i==len){
        if(k==0)return 1;
        else return 0;
    }
    if(k==0)return 1;
    if(smaller){
        return nCr(len-i,k)*pow(9,k);
    }else if(n[i]=='0'){
        return solve(i+1,k,smaller);
    }else{
        ll strict_small=solve(i+1,k,true);
        ll mid=solve(i+1,k-1,true)*(n[i]-'0'-1);
        ll max=solve(i+1,k-1,false);
        return strict_small+mid+max;
    }
}

signed main(void){
    cin>>n>>k;
    len=n.size();
    cout << solve(0,k,false) << endl;
}

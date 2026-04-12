#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vin=vector<int>;
using vll=vector<long long>;
using vdo=vector<double>;
using vvin=vector<vector<int>>;
using vvll=vector<vector<long long>>;
using vvdo=vector<vector<double>>;
using vstr=vector<string>;
using vvstr=vector<vector<string>>;
using pqin=priority_queue<int>;
using pqsin=priority_queue<int,vector<int>,greater<int>>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(s);i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define _GLIBCXX_DEBUG
int main()
{
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    int ans;
    int d=2*max(x,y)+1;
    vin sum(d);
    rep(l,d){
        if(l<=x&&l<=y)sum[l]=a*x+b*y+(2*c-a-b)*l;
        else if(l>x&&l<=y)sum[l]=b*y+(2*c-b)*l;
        else if(l<=x&&l>y)sum[l]=a*x+(2*c-a)*l;
        else if(l>x&&l>y)sum[l]=2*c*l;
    }
    sort(all(sum));
    cout<<sum[0]<<endl;
}
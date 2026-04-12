#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vin=vector<int>;
using vll=vector<long long>;
using vvin=vector<vector<int>>;
using vvll=vector<vector<long long>>;
using vstr=vector<string>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(s);i<(int)(n);i++)
#define _GLIBCXX_DEBUG
int main()
{
    int n;
    cin>>n;
    vin h(n);
    rep(i,n)cin>>h[i];
    int sum=1;
    rep2(i,1,n){
        bool can=true;
        rep(j,i){
            if(h[j]>h[i]){
                can=false;
                break;
            }
        }
        if(can)sum++;
    }
    cout<<sum<<endl;
}
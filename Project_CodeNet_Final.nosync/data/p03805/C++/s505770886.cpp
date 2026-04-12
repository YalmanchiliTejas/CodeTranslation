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
using vch=vector<char>;
using vvch=vector<vector<char>>;
using pqin=priority_queue<int>;
using pqsin=priority_queue<int,vector<int>,greater<int>>;
#define mp make_pair
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(s);i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define decp(n) cout<<fixed<<setprecision((int)n)
#define _GLIBCXX_DEBUG
int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> p(m);
    rep(i,m){
        int a,b;
        cin>>a>>b;
        p[i]=mp(a,b);
    }
    vin tmp(n);
    rep(i,n-1)tmp[i]=i+2;
    int sum=0;
    if(n>2){
        do{
            vector<bool> ar(n,true);
            bool can1=false;
            rep(i,m){
                if(p[i].first==1&&p[i].second==tmp[0]){
                    ar[1]=false;
                    can1=true;
                }
            }
            if(can1){
                rep(i,n-2){
                    bool can2=false;
                    rep(j,m){
                        if(p[j].first==tmp[i]&&p[j].second==tmp[i+1]&&ar[i+2]){
                            ar[i+2]=false;
                           can2=true;
                        }
                        else if(p[j].second==tmp[i]&&p[j].first==tmp[i+1]&&ar[i+2]){
                            ar[i+2]=false;
                            can2=true;
                        }
                    }
                    if(!can2){
                        can1=false;
                        break;
                    }
                }
                if(can1)sum++;
            }
        }while(next_permutation(all(tmp)));
    }
    if(n==2)sum=1;
    cout<<sum<<endl;
}
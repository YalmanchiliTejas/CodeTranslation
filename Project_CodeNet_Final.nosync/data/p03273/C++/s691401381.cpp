#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001001001001
#define mod 1000000007
#define mod2 998244353
#define pi acos(-1)
#define all(v) v.begin(),v.end()
int main(){
    int H,W;cin>>H>>W;
    vector<vector<char>>c(H,vector<char>(W));
    rep(i,H)rep(j,W){
        cin>>c.at(i).at(j);
    }
    set<int>retu;
    set<int>gyou;
    int count=0;
    rep(i,H){
        rep(j,W){
            if(c.at(i).at(j)=='#'){
                break;
            }else{
                count++;
                continue;
            }
        }
        if(count==W){
            retu.insert(i);
        }
        count=0;
    }
    rep(j,W){
        rep(i,H){
            if(c.at(i).at(j)=='#'){
                break;
            }else{
                count++;
                continue;
            }
        }
        if(count==H){
            gyou.insert(j);
        }
        count=0;
    }
    rep(i,H){
        rep(j,W){
            if(gyou.count(j) || retu.count(i)){
                continue;
            }else{
                cout<<c.at(i).at(j);
            }
        }
        if(!retu.count(i))cout<<endl;
    }
}
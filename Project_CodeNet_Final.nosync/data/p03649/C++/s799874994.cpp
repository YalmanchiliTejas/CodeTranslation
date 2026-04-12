#pragma GCC optimize("Ofast")
#include<cstdio>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include <bitset>
#include <cmath>
#include <limits>
#include <iostream>
#include <map>
using namespace std;
#define INF 1LL<<62
#define MAX 100000
#define MOD 1000000007
typedef long long ll;
typedef pair<int,int> P;
typedef pair<pair<int,int>,int> p;
#define bit(n,k) ((n>>k)&1) /*nのk bit目*/
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)
struct edge{ll to,cost,val;};
template<class T,class U>bool chmin(T&a,const U&b){if(a<=b)return false;a=b;return true;}
template<class T,class U>bool chmax(T&a,const U&b){if(a>=b)return false;a=b;return true;}
//__builtin_popcount(S);
//C.erase(unique(C.begin(),C.end()),C.end());
//#define int ll

signed main(){
    int N;
    cin>>N;
    ll a[60];
    for(int i=1;i<=N;i++) cin>>a[i];

    bool flag=true;
    ll count=0;
    while(flag){
        flag=false;
        for(int i=1;i<=N;i++){
            if(a[i]<N) continue;
            flag=true;
            ll t=a[i]/N;
            count+=t;
            a[i]-=N*t;
            for(int j=1;j<=N;j++){
                if(i==j) continue;
                a[j]+=t;
            }
        }
    }
    cout<<count<<endl;
}

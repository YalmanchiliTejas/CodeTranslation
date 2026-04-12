#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
#include <iomanip>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> P;
typedef pair<P,P> PP;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=9999999999;


int main(){
    int h,w;
    cin>>h>>w;
    vector<string> G(h);
    for(int i=0;i<h;i++) cin>>G[i];

    vector<string> buf;
    for(int i=0;i<h;i++){
        bool f=true;
        for(int j=0;j<w;j++){
            if(G[i][j]=='#') f=false;
        }
        if(!f) buf.push_back(G[i]);
    }

    for(int j=0;j<w;j++){
        bool f=true;
        for(int i=0;i<buf.size();i++){
            if(buf[i][j]=='#') f=false;
        }
        if(f){
            for(int i=0;i<buf.size();i++){
                buf[i][j]='?';
            }
        }
    }

    for(int i=0;i<buf.size();i++){
        for(int j=0;j<w;j++){
            if(buf[i][j]=='?') continue;
            cout<<buf[i][j];
        }
        cout<<endl;
    }

}
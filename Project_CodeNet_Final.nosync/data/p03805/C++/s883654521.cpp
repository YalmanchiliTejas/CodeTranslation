#define _USE_MATH_DEFINES
#include <sstream> //string stream its useful!
#include<string>
#include<iostream>
#include<utility> //pair
#include <vector> // vector
#include <algorithm>    // swap,sort,binary_search
#include <functional>   // std::greater
#include <map> //map
#include<set> //set
#include<queue> //queue
#include<list> //list
#include<cmath>
#include<numeric>
#include<cassert>
#include <iomanip> //cout<<setprecision
#include <regex>

typedef long long ll;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
ll W = 1000000007;
// tuple にすれば回るんじゃないかな。


using namespace std;
void omajinai() {
    
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout<<setprecision(15);
    //freopen("txt.csv","r",stdin);
}



static function<ll(ll,ll)> sumfunc = [](ll l1,ll l2)->ll{return l1 + l2;};
class UF{
public:
    vector<ll> v;
    vector<ll> v2;
    function<ll(ll,ll)> func;
    UF(long t,function<ll(ll,ll)> func){
        v = vector<ll>(t);
        v2 = vector<ll>(t);
        for(int i = 0; i<v.size();i++) v[i] = i;
        this->func = func;
    }
    long getunion(long t){
        if(v[t] == t) return t;
        v[t] = getunion(v[t]);
        return v[t];
    }
    void unite(pair<long,long> p){
        long a = getunion(p.first), b = getunion(p.second);
        if(a>b) swap(a,b);
        v[b] = a;
        v2[a] = func(v2[b],v2[a]);
    }
    long sizeofunion(){
        long sum = 0;
        for(int i = 0 ; i<v.size();i++) if(v[i] == i ) sum++;
        return sum;
    }
};

class Main{
public:
    
    int M,N;
    vector<vector<int> > c;
    Main(){
        cin>>N>>M;
        c = vector<vector<int> >(N+1,vector<int>(N+1,0));
        REP(i,M){
            int j,k;
            cin>>j>>k;
            c[j][k] = 1; c[k][j] = 1;
        }
    }
    
    void run(){
        int ans = 0;
        queue<pair<long,int> > q;
        q.push(make_pair(1<<1,1));
        while(!q.empty()){
            pair<long,int> p = q.front();
            q.pop();
            FOR(i,1,N+1){
                if( !(p.first&(1<<i)) && c[p.second][i] == 1){
                    q.push(make_pair(p.first + (1<<i),i));
                    if(p.first + (1<<i) == (1<<(N+1))-2) ans++;
                }
            }
        }
        cout<<ans<<endl;
        return;
    }
};

int main(){
    omajinai();
    Main().run();
}

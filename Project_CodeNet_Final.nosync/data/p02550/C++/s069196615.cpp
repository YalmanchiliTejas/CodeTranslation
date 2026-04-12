#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <list>
#include <ctime>
#include <complex>
#include <bitset>
#include <tuple>
#include <random>

#define ff first
#define ss second

using namespace std;

using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

#define MOD 998244353LL

pii operator+(pii a, pii b)
{
    return {a.ff+b.ff,a.ss+b.ss};
}

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0);
    
    ll n,x,m;
    cin>>n>>x>>m;
    ll now=x;
    vector<ll> sum={now};
    vector<int> idx(100000,-1);
    idx[now]=0;
    ll answer=now;
    n-=1;
    while(n--){
        now=((now%m)*(now%m))%m;
        if(idx[now]!=-1){
            answer+=now;
            ll tmp=sum.back();
            ll siz=(int)sum.size()-idx[now];
            if(idx[now]!=0) tmp-=sum[idx[now]-1];
            answer+=tmp*(n/siz);
            answer+=sum[idx[now]+n%siz];
            answer-=sum[idx[now]];
            break;
        }
        else{
            idx[now]=sum.size();
            sum.push_back(sum.back()+now);
            answer+=now;
        }
    }
    cout<<answer;

    return 0;
}

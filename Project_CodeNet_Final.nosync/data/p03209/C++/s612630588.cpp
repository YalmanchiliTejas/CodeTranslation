#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<map>
#include<queue>
#define REP(i,a) for (int i = 0;i < (a);++i)
#define FOR(i,a,b) for (int i = (a);i < (b); ++i)
#define FORR(i,a,b) for (int i = (a);i >= (b); --i)
#define ALL(obj) (obj).begin(),(obj).end()
#define SORT(list) sort(ALL((list)));
#define MOD 1000000007
#define MAX_TICK 1125899906842623
using namespace std;
using ll = long long;
vector<ll> t(51),p(51);
ll answer = 0;
void eat(ll ref_level,ll tick){
    if(tick <= 0)return;
    //cerr << ref_level;
    int level = lower_bound(t.begin(),t.end(),tick)-t.begin();
    if(t[ref_level] > tick){
        //cerr << "a";
        eat(--ref_level,--tick);
    }else if(t[ref_level] < tick){
        //cerr << "b";
        answer+=p[ref_level];
        tick-=1;
        answer++;
        tick-=t[ref_level];
        /*if(tick >= t[ref_level]){
            answer+=p[ref_level];
            return;
        }
        eat(--ref_level,tick);*/
        eat(ref_level,tick);
    }else{
        //cerr << "c";
        answer += p[ref_level];
        return;
    }
}
int main(){
    ll n,x;
    cin >> n >> x;
    t[0]=p[0]=1;
    REP(i,50){
        t[i+1] = t[i]*2+3;
        p[i+1] = p[i]*2+1;
    }

    /*int level = lower_bound(t.begin(),t.end(),x)-t.begin();
    REP(i,n){
        //cerr << t[i] << endl;
        cerr << p[i] << endl;
    }*/

    eat(n,x);

    cout << answer << endl;

    return 0;
}

#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()
#define LL long long
#define pll pair<LL,LL>

using namespace std;

int main(){

    int N;cin>>N;
    LL xmax=-10000000000LL,xmin=10000000000LL,ymax=-10000000000LL,ymin=10000000000LL;
    priority_queue<pll,vector<pll>,greater<pll> > que;

    REP(i,N){
        LL x,y;cin>>x>>y;
        if(x<y)swap(x,y);
        xmax = max(xmax,x);
        xmin = min(xmin,x);
        ymax = max(ymax,y);
        que.push({y,x});
    }

    LL ans = (xmax - xmin)*(ymax - que.top().first);

    REP(i,N-1){
        pll p = que.top();que.pop();
        xmin = min(xmin, p.first);
        ymax = max(ymax,p.second);
        ymin = min(ymin,p.second);
        ans = min(ans,(xmax-xmin)*(ymax-min(ymin,que.top().first)));
    }

    cout<<ans<<endl;

    return 0;
}
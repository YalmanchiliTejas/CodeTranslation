#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>
#include <stack>
#include <numeric>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf 1000000007
#define mod 998244353
#define rep(i,n) for(int i=0;i<(int)(n);++i)


int main(){
    int a,b;
    cin >> a >> b;
    vector<vector<int> > d(a,vector<int>(b));
    rep(i,a){
        rep(j,b){
            cin >> d[i][j];
        }
    }
    int n,m;
    n = 200;
    int s = 203;
    int t = 204;
    bool flag = 0;
    vector<vector< int > > p(101,vector<int>(101,-inf));
    rep(i,101){
        rep(j,101){
            rep(k,a){
                rep(l,b){
                    p[i][j] = max(d[k][l]-i*(k+1)-j*(l+1),p[i][j]);
                }
            }
        }
    }
    // rep(i,3){
    //     rep(j,3){
    //         cerr << i << " " << j << " " <<  p[i][j] << endl;
    //     }
    // }
    vector<pair<pair<int,int>,int> > edge;
    vector<vector<pair<int,int> > > g(210);
    vector<int> x(101);
    vector<int> y(101);
    rep(i,101){
        x[i] = 1+i;
        y[i] = 202-i;
    }
    g[s].push_back(MP(x[0],0));
    g[y[0]].push_back(MP(t,0));
    edge.push_back(MP(MP(s,x[0]),0));
    edge.push_back(MP(MP(y[0],t),0));
    rep(i,100){
        g[x[i]].push_back(MP(x[i+1],mod));
        g[y[i+1]].push_back(MP(y[i],mod/2));
        edge.push_back(MP(MP(x[i],x[i+1]),mod));
        edge.push_back(MP(MP(y[i+1],y[i]),mod/2));
    }
    rep(i,101){
        rep(j,101){
            if(p[i][j]>=0){
                g[x[i]].push_back(MP(y[j],p[i][j]));
                edge.push_back(MP(MP(x[i],y[j]),p[i][j]));
            }
        }
    }
    rep(i,a){
        rep(j,b){
            int cx = i+1;
            int cy = j+1;
            priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >  pq;
            pq.push(MP(s,0));
            vector<int> dst(400,inf);
            dst[s] = 0;
            while(!pq.empty()){
                auto x = pq.top();
                int id = x.first;
                
                pq.pop();
                if(x.second > dst[id])continue;
                //cerr << id << " " << dst[id] << endl;
                for(auto y:g[id]){
                    int cs = 0;
                    if(y.second==mod){
                        cs = cx;
                    }else if(y.second==mod/2){
                        cs = cy;
                    }else{
                        cs = y.second;
                    }
                    if(dst[y.first]>dst[id]+cs){
                        dst[y.first] = dst[id]+cs;
                        pq.push(MP(y.first,dst[y.first]));
                    }
                }
            }
            //cerr << i << " " << j << " " << d[i][j] << " " <<  dst[t] << endl;
            if(dst[t]!=d[i][j]){
                cout <<"Impossible" << endl;
                return 0;
            }
        }
    }
    cout << "Possible" << endl;
    cout << 300 << " " << edge.size() << endl;
    for(auto x:edge){
        cout << x.first.first << " " << x.first.second << " " ;
        if(x.second==mod){
            cout << "X" << endl;
        }else if(x.second==mod/2){
            cout << "Y" << endl;
        }else{
            cout << x.second << endl;
        }
    }
    cout << s << " " << t << endl;
    return 0;
}
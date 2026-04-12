#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int n,d[100000];
P p[100000];
set<int> c,g;
set<P> s;
ll yen=0;
priority_queue<P, vector<P>, greater<P> > q;


int dist(int a, int b){
    return min(abs(p[a].first-p[b].first), abs(p[a].second-p[b].second));
}

void f(int z){
    g.insert(z); //
    c.erase(z);
    if(z-1>=0&&z-1<n){
        if(g.find(z-1)==g.end()){
            c.insert(z-1);
            d[z-1]=min(d[z-1], dist(z-1, z));
            q.push(P(d[z-1], z-1));
        }
    }
    if(z+1>=0&&z+1<n){
        if(g.find(z+1)==g.end()){
            c.insert(z+1);
            d[z+1]=min(d[z+1], dist(z+1, z));
            q.push(P(d[z+1], z+1));
        }
    }
    auto itrZ=s.find(P(p[z].second, z));
    if(itrZ!=s.end()){
        auto itrP=itrZ;
        itrP++;
        if(itrP!=s.end()){
            int zp=(*itrP).second;
            if(g.find(zp)==g.end()){
                c.insert(zp);
                d[zp]=min(d[zp], dist(zp, z));
                q.push(P(d[zp], zp));
            }
        }
        if(itrZ!=s.begin()){
            itrZ--;
            int zp=(*itrZ).second;
            if(g.find(zp)==g.end()){
                c.insert(zp);
                d[zp]=min(d[zp], dist(zp, z));
                q.push(P(d[zp], zp));
            }
        }
    }
}

int main(void){
    cin>>n;

    fill(d, d+n,1e9+7);
    for(int i=0;i<n;i++){
        cin>>p[i].first>>p[i].second;
    }
    sort(p, p+n);
    for(int i=0;i<n;i++){
        s.insert(P(p[i].second, i));
    }
    f(0);

    while(!c.empty()&&!q.empty()){
        P can=q.top();
        q.pop();
        int ind=can.second,cost=can.first;
        if(g.find(ind)==g.end()){
            f(ind);
            yen+=(ll)cost;
            //cout<<"---("<<ind<<")+"<<cost<<endl;
        }

        //break;
    }

    cout<<yen<<endl;
}

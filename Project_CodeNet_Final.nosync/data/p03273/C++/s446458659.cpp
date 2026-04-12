#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define int long long
#define vec(a,n) vector<int> (a)((n))
#define Vec(a,n) vector<string> (a)((n))
#define twovec(a,n,m) vector<vector<int>> a(n,vector<int>(m,0))
#define Twovec(a,n,m) vector<vector<double>> a(n,vector<double>(m,0))
#define P pair<int,int>
#define Sort(a) sort((a).begin(),(a).end())
#define Reverse(a) reverse((a).begin(),(a).end())
#define PQ(n) priority_queue<P,vector<P>,greater<P>> (n)
#define pq(n) priority_queue<int> (n)
using namespace std;
void Debug(auto a);

signed main(){
    int h,w;
    cin >> h >> w;
    Vec(a,h);
    vector<string> b;
    REP(i,h){
        cin >> a[i];
    }
    bool er=false;
    REP(i,h){
        er=false;
        REP(j,w){
            if(a[i][j]=='#'){
                er = true;
            }
        }
        if(er){
            b.push_back(a[i]);
        }
        
    }
    h = b.size();
    Vec(c,h);
    copy(b.begin(),b.end(),c.begin());
    int tmp=0;
    REP(i,w){
        er=true;
        REP(j,h){
            if(b[j][i] == '#'){
                er=false;
            }
        }
        if(er){
            REP(j,h){
                c[j].erase(c[j].begin()+i-tmp);
                
            }
          tmp++;
        }
    }
    for(auto d: c){
        cout << d << endl;
    }
    
    
    return 0;
}
void Debug(auto a){
    cout << "{ ";
    for(auto b: a){
        cout << b << " ";
    }
    cout << "}" << endl;
}
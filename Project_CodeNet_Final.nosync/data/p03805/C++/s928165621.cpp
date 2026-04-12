#include <bits/stdc++.h>
using namespace std;
 
#define REP(i, s) for (int i = 0; i < s; ++i)
#define ALL(v) (v).begin(), (v).end()
#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
#define EACH(i, s) for (__typeof__((s).begin()) i = (s).begin(); i != (s).end(); ++i)
#define DEBUG
#define int long long
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T1, class T2> ostream& operator << (ostream &s, pair<T1,T2> P)
{ return s << '<' << P.first << ", " << P.second << '>'; }
template<class T> ostream& operator << (ostream &s, vector<T> P)
{ for (int i = 0; i < P.size(); ++i) { if (i > 0) { s << " "; } s << P[i]; } return s; }
template<class T> ostream& operator << (ostream &s, vector<vector<T> > P)
{ for (int i = 0; i < P.size(); ++i) { s << endl << P[i]; } return s << endl; }
template<class T> ostream& operator << (ostream &s, set<T> P)
{ EACH(it, P) { s << "<" << *it << "> "; } return s << endl; }
template<class T1, class T2> ostream& operator << (ostream &s, map<T1,T2> P)
{ EACH(it, P) { s << "<" << it->first << "->" << it->second << "> "; } return s << endl; }
template<class T>void show(vector <T> v){for (int i = 0; i < v.size(); i++){cerr<<v[i]<<" ";}cerr<<"\n";}
typedef long long ll;

bool visit[10];
bool graph[10][10];
int dfs(int p,int n,bool * visit){
    bool all_vis=true;
    for (int i = 0; i < n; i++)
    {
        if(!visit[i]){
            all_vis=false;
        } 
    }
    if(all_vis) {
        return 1;
    } 
    int res=0;
    for (int i = 0; i < n; i++)
    {
        if(!graph[p][i]) continue;
        if(visit[i]) continue;
        visit[i]=true;
        res+=dfs(i,n,visit);
        visit[i]=false;
    }
    return res;
}

signed main(){
    int n,m;
    cin>>n>>m;
   
    for (int i = 0; i < m; i++)
    {
        int a,b;
        cin>>a>>b;
        a--,b--;
        graph[a][b]=graph[b][a]=true;       
    }
    visit[0]=true;
    cout<<dfs(0,n,visit)<<endl;
   
    return 0;
}
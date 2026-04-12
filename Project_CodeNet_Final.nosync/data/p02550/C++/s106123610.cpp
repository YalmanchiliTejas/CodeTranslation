#include <bits/stdc++.h>
using namespace std;
 
#define REP(i, s) for (int i = 0; i < s; ++i)
#define ALL(v) (v).begin(), (v).end()
#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
#define EACH(i, s) for (__typeof__((s).begin()) i = (s).begin(); i != (s).end(); ++i)
#define DEBUG
#define int long long
#define INF 1e18
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
template<class T>void show(vector<T>v){for (int i = 0; i < v.size(); i++){cerr<<v[i]<<" ";}cerr<<"\n";}
typedef long long ll;


signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,x,m;
    cin>>n>>x>>m;
    vector<int>ok(m+1,false);
    vector<int>a;
    int cnt=0;
    a.push_back(x);
    ok[x]=true;
    if(n<=m){
        int ans=0;
    for (int i = 0; i < n; i++)
    {
       ans+=x%m;
       x=(x*x)%m;
    }
    cout<<ans<<endl;
    }
    else{
        int num=-1;
        for (int i = 0; i < n; i++)
        {
            x=(x*x)%m;
            if(ok[x]){
                num=x;
                cnt=i+1;
                break;
            }
            ok[x]=true;
            a.push_back(x);
        }
        int id=-1;
        int ans1=0;
        for (int i = 0; i < a.size(); i++)
        {
            if(a[i]==num){
                //ans1+=a[i];
                id=i;
                break;
            }
            ans1+=a[i];
        }
        n-=id;
        int shuki=a.size()-id;
        int ans2=0;
        for (int i = id; i < a.size(); i++)
        {
            ans2+=a[i];
        }
        int ans3=0;
        for (int i = id; i < id + n%shuki; i++)
        {
            ans3+=a[i];
        }
       // show(a);
       // cerr<<ans1<<" "<<ans2<<" "<<ans3<<endl;
        cout<<ans1+ans2* (n/shuki)+ans3<<endl;

        
    }

    return 0;
}
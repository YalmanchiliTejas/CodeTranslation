#include <bits/stdc++.h>
using namespace std;
 
#define REP(i, s) for (int i = 0; i < s; ++i)
#define ALL(v) (v).begin(), (v).end()
#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
#define EACH(i, s) for (__typeof__((s).begin()) i = (s).begin(); i != (s).end(); ++i)
#define DEBUG
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
 int v[60][30];
int main(){
    int n;
    cin>>n;
    vector<string>s(n);
    map<pair<int,string>,int>mp;
    //vector<vector<int>>>v(n,0);
   
    for (int i = 0; i < n; i++)
    {
        cin>>s[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < s[i].size(); j++)
        {
           v[i][s[i][j]-'a']++;
        }
        
    }
    string t;
    for (int j = 0; j <=25; j++)
    {
        
        int min_c=60;
        for (int i = 0; i < n; i++)
        {
            if(min_c>v[i][j]){
                min_c=v[i][j];
            }
        }
        for (int k = 0; k < min_c; k++)
        {
            t.push_back('a'+j);
        }    
    }
    sort(ALL(t));
    cout<<t<<endl;

    return 0;
}
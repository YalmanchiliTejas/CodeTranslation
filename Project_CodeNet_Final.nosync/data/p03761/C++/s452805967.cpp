#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <numeric>
#include <utility>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <unordered_map>
using namespace std;

#define REP(i, s) for (int i = 0; i < s; ++i)
#define ALL(v) (v.begin(), v.end())
#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
#define EACH(i, s) for (__typeof__((s).begin()) i = (s).begin(); i != (s).end(); ++i)

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

typedef long long  ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
char v[60][60];
int n;
int w[50][30];
int main() {
    
    
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    //初期化
    for(int i=0;i<50;i++){
        for(int j=0;j<30;j++){
            w[i][j]=0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<=50;j++){
            w[i][v[i][j]-'a']++;
        }
    }
    //cout<<w[2][0]<<endl;
    int min=60;
    int a[26];
    for(int i=0;i<26;i++){
        a[i]=0;
    }

    for(int i=0;i<26;i++){
        int min=60;
        for(int j=0;j<n;j++){
            if(min>w[j][i]){
                min=w[j][i];
            }
        }
        a[i]=min;
        while(a[i]>0){
            cout<<(char)(i+'a');
            a[i]--;
        }

    }
    printf("\n");


    return 0;
}
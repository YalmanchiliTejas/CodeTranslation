#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cctype>
#include <climits>
#include <string>
#include <bitset>
using namespace std;
typedef long double ld;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<pair<int,int> > vpii;
typedef vector<vector<int> > vvi;
typedef vector<vector<char> > vvc;
typedef vector<vector<string> > vvs;
typedef vector<vector<ll> > vvll;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define fin(ans) cout<<(ans)<<endl
#define STI(s) atoi(s.c_str())
#define mp(p,q) make_pair(p,q)
#define pb(n) push_back(n)
#define Sort(a) sort(a.begin(),a.end())
#define Rort(a) sort(a.rbegin(),a.rend())
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
const int P = 1000000007;
const int INF = INT_MAX;
const long long LLINF = 1LL<<60;
//g++ -std=c++1z temp.cpp
//./a.out


string jfen(vs v){
    string s;
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            int num=0;
            while(j<v[i].size()&&v[i][j]=='.'){
                num++;
                j++;
            }
            if(num==0){
                s+='b';
            }
            else{
                s+=char(num+'0');
                j--;
            }
        }
        s+='/';
    }
    s=s.substr(0,s.size()-1);
    return s;
}

int main(void){ios::sync_with_stdio(false);cin.tie(0);
//////////////////////////////////////////////////////
	string s;
    int a,b,c,d;
    while(1){
        cin>>s;
        if(s=="#")break;
        cin>>a>>b>>c>>d;
        vs v(1,"");
        int h=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='/'){
                // v[h].push_back('/');
                v.push_back("");
                h++;
            }
            else if(s[i]<='9'&&s[i]>='0'){
                for(int j=0;j<s[i]-'0';j++){
                    v[h]+='.';
                }
            }
            else{
                v[h]+=s[i];
            }
        }
        // v[h].push_back('%');
        //move
        v[a-1][b-1]='.';
        v[c-1][d-1]='b';
        cout<<jfen(v)<<endl;
    }
    
/////////////////////////////////////////////////////
return 0;}


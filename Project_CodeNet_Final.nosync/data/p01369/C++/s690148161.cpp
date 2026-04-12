#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1<<29
#define LINF LLONG_MAX/3
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define ALL(v) (v).begin(),(v).end()
#define debug(x) cerr<<#x<<":"<<x<<endl
#define debug2(x,y) cerr<<#x<<","<<#y":"<<x<<","<<y<<endl
#define CININIT cin.tie(0),ios::sync_with_stdio(false)
template<typename T> ostream& operator<<(ostream& os,const vector<T>& vec){ os << "["; for(const auto& v : vec){ os << v << ","; } os << "]"; return os; }

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main(){
    CININIT;

    string s;
    string left = "qwertasdfgzxcvb";
    string right = "yuiophjklnm";

    map<char,int> m;
    for(char c:left) m[c] = 0;
    for(char c:right) m[c] = 1;

    while(cin>>s){
        if(s=="#") break;
        vector<int> x(s.size()+1);
        for(int i=0;i<s.size();i++) x[i] = m[s[i]];
        x[s.size()] = x[s.size()-1];

        int cnt=0;
        for(int i=0;i<s.size();i++){
            if(x[i]!=x[i+1]) cnt++;
        }
        cout << cnt << endl;
    }
}
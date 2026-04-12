#include <bits/stdc++.h>

using namespace std;

#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define MOD 1000000007
#define NUM 2520
#define INF (1LL<<50)
#define DEBUG 0
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)

lli data[50][26];
lli ans[26];

signed main(){

    lli n;
    cin>>n;

    REP(i,0,n){
        string s;
        cin>>s;
        REP(j,0,s.size()){
            data[i][s.at(j)-'a']++;
        }
    }

    REP(i,0,26){
        lli cnt=INF;
        REP(j,0,n){
            cnt=min(cnt,data[j][i]);
        }
        ans[i]=cnt;
    }

    REP(i,0,26){
        REP(j,0,ans[i])cout<<(char)(i+'a');
    }
    cout<<endl;

	return 0;
}
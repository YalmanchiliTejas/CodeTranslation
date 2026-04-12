#include "bits/stdc++.h"
using namespace std;
#define PB push_back
#define MP make_pair
#define REP(i,n) for(int i=0;i<(n);i++)
int main(){
    int cnt[50][26];
    memset(cnt,0,sizeof(cnt));
    int n;
    cin>>n;
    string s;
    REP(i,n){
        cin>>s;
        REP(j,s.size())cnt[i][s[j]-'a']++;
    }
    REP(i,26){
        int mi=1e9;
        REP(j,n)mi=min(mi,cnt[j][i]);
        REP(j,mi)printf("%c",'a'+i);
    }cout<<endl;
}
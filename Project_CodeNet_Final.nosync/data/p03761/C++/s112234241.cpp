#include <bits/stdc++.h>
    
#define int long long
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define FORR(i,m,n) for(int i=m;i>=n;i--)
#define pb(x) push_back(x)
#define all(x) ((x).begin(), (x).end())
#define mp(x, y) make_pair(x, y) 
#define SORT(x) sort((x).begin(), (x).end())
#define INF 99999999999
#define MOD (int)(1e9)+7
    
using namespace std;
    
int dy[4]={1, 0, -1, 0};
int dx[4]={0, 1, 0, -1};

int32_t main(){
    int n;
    cin >> n;
    vector<int> v((int)('z'-'a')+1, 0);
    REP(i, n){
        string s;
        cin >> s;

        if(i==0){
            REP(j, s.length()){
                v[s[j]-'a']++;
            }
        }
        else{
            vector<int> t((int)('z'-'a')+1, 0);
            REP(j, s.length()){
                t[s[j]-'a']++;
            }
            REP(j, (int)('z'-'a')+1){
                v[j]=min(v[j], t[j]);
            }
        }
    }
    

    string str="";
    REP(i, (int)('z'-'a')+1){
        REP(j, v[i]){
            str+=(char)('a'+i);
        }
    }

    cout << str << endl;
}
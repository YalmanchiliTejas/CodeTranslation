#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define pb(s) push_back(s)
#define mp(a,b) make_pair(a,b)
#define f first
#define s second
#define ALL(v) v.begin(), v.end()
#define ALLA(arr, sz) arr, arr + sz
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr, sz) sort(ALLA(arr, sz))
#define REVERSEA(arr, sz) reverse(ALLA(arr, sz))
#define PI 3.14159265358979323846264338327950L
#define MOD 1000000007

typedef long long ll;

vector<string> v;

void rid(char ch){
    for(int i=1;i<v.size();++i){
        v[i].erase(v[i].find(ch),1);
        continue;
    }
}

bool check(char ch){

    for(int i=1;i<v.size();++i){
        if(v[i].find(ch)==string::npos)return 0;
    }
    return 1;
}

void solve()
{
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        string x;
        cin>>x;
        SORT(x);
        v.pb(x);
    }
    string ans="";
    for(int i=0;i<v[0].size();++i){
        if(check(v[0][i])){
            ans+=v[0][i];
            rid(v[0][i]);
        }
    }
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //int t;
    //cin>>t;
    //while(t--)
    solve();
    return 0;
}

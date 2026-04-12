#include<bits/stdc++.h>
using namespace std;

#define rp(i,n) for(int i=0;i<n;i++)
#define rep(i,m,n) for(int i=m;i<=n;i++)
#define lrp(i,n) for(long long i=0;i<n;i++)
#define lrep(i,m,n) for(long long i=m;i<=n;i++)
#define sort(a) sort(a.begin(),a.end())
#define reverse(a) reverse(a.begin(),a.end())
#define pb push_back
#define elif else if

typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<string> vs;
typedef vector<char> vc;
typedef long long ll;
typedef string S;

int n,m,ans;
int a[30],b[30];
bool pass[8],pass2[8];
bool graph[8][8];
void dfs(int p){
    pass[p]=true;
    bool all_visited=true;
    rp(i,n){
        if(!(pass[i])){
            all_visited=false;
        }
    }
    if(all_visited){
        ans++;
    }
    rp(i,n){
        if(pass[i]==false&&graph[p][i]){
            dfs(i);
            pass[i]=false;
        }
    }
}

int main(){
    ans=0;
    cin >> n >> m;
    rp(i,m){
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
        graph[a[i]][b[i]]=true;
        graph[b[i]][a[i]]=true;
    }
    rp(i,n){
        pass[i]=false;
    }
    dfs(0);
    cout << ans << endl;
    return 0;
}


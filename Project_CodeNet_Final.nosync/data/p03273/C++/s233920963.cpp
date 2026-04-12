#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)

#define FOR(i,n,j) for(int i=(j);i<(n);++i)
#define ssort(n) sort((n).begin(),(n).end())
#define rsort(n) sort((n).begin(),(n).end(),greater<int>())
using ll=long long;
using ld=long double;
typedef pair<int,int> P;
typedef pair<P,int> COST;
#define repl(i,n) for(ll i=0;i<(n);++i)
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
using Graf=vector<vector<char>>;

int main()
{
    int h,w;
    cin >> h >> w;
    Graf g(h+1,vector<char>(w+1));
    rep(i,h){
        rep(j,w){
            cin >> g[i][j];
        }
    }
    int count;
    rep(i,h){
        count=0;
        rep(j,w){
            if(g[i][j]=='#'){
                break;
            }
            count++;
        }
        if(count==w){
            g[i][w]='1';
        }else{
            g[i][w]='0';
        }
    }
    rep(j,w){
        count=0;
        rep(i,h){
            if(g[i][j]=='#'){
                break;
            }
            count++;
        }
        if(count==h){
            g[h][j]='1';
        }else{
            g[h][j]='0';
        }
    }

    rep(i,h){
        if(g[i][w]=='0'){
            rep(j,w){
                if(g[h][j]=='0'){
                    cout << g[i][j];
                }
            }
            cout << endl;
        }
        

    }
}
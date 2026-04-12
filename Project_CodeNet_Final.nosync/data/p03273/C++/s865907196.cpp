#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000005LL
#define MOD 1000000007
using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
int main(){
    int h,w;
    cin >> h >> w;
    vector<vector<char>> field(h,vector<char>(w));
    rep(i,0,h){
        rep(j,0,w){
            cin >> field[i][j];
        }
    }
    set<int> ommith;
    set<int> ommitw;
    rep(i,0,h){
        int check = 0;
        rep(j,0,w){
            if(field[i][j]!='.'){
                check=1;
            }
        }
        if(check==0){
            ommith.insert(i);
        }
  
    }
    rep(i,0,w){
        int check = 0;
        rep(j,0,h){
            if(field[j][i]!='.'){
                check=1;
            }
        }
        if(check==0){
            ommitw.insert(i);
        }
  
    }
    rep(i,0,h){
        if(ommith.count(i)){
            continue;
        }
        rep(j,0,w){
            if(ommitw.count(j)){
                continue;
            }
            cout<<field[i][j];
            
        }
        cout<<endl;
    }
    
  return 0;
}
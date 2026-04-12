#include "bits/stdc++.h"

#define sp <<" "
#define el <<"\n"
#define S second
#define F first
#define mp make_pair
#define pb push_back
#define pf push_front
#define pob pop_back
#define obit __builtin_popcount
#define pof pop_front
#define pai pair<int,int> 
#define For(i,a,n) for(i=a;i<n;i++)
#define all(ar) ar.begin(),ar.end() 
using namespace std;

typedef long long ll;
typedef unsigned long long ul;
typedef unsigned short int us;
typedef short int ss;
typedef long double ld;
const ll mod = 1000000007;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    /*
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    //*/
    int i,j,h,w;
    cin>>h>>w;
    string ar[h];
    set<pai> hash;
    set<int> row,col;
    For(i,0,h) cin>>ar[i];
    For(i,0,h){
        For(j,0,w){
            if(ar[i][j] == '#'){
                hash.insert({i,j});
                row.insert(i); col.insert(j);
            }
        }
    }
    For(i,0,h){
        if(row.count(i)){
            For(j,0,w){
                if(col.count(j)){
                    if(hash.count({i,j})) cout<<"#";
                    else cout<<".";
                }
            }
            cout el;
        }
    }
    return 0;
}
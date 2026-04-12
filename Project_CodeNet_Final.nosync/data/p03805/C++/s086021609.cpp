#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<utility>
#include<cstdio>
#include<set>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include <bitset>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,x,n) for (int i= x;i<n;i++)
#define all(v) v.begin(), v.end()
#define nepe(v) next_permutation(all(v))
using ll = long long;
using vi = vector<int>; 
using vvi = vector<vi>;

typedef pair<int,int> P;
string s;
int k;
ll INF = 10000000000000000;

int main(){
    int ans = 0;
    int N,M;
    cin >> N >> M;
    vvi path(N,vi(N,0));

    rep(i,M){
        int a,b;
        cin >>a>>b;
        path[a-1][b-1] = 1;
        path[b-1][a-1] = 1;
    }

    vi order(N-1);
    rep(i,N-1){
        order[i]=i;
    }

    do{
        bool judge = true;
        if(path[0][order[0]+1]==0)  judge =false;
        rep(i,N-2){
            if(path[order[i]+1][order[i+1]+1]==0) judge = false;
        }
        if(judge) ans++;
    }while(nepe(order));
    cout << ans <<endl;
}
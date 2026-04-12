#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define int long long
#define vec(a,n) vector<int> (a)((n))
#define Vec(a,n) vector<string> (a)((n))
#define P pair<int,int>
#define PQ(n) priority_queue<P,vector<P>,greater<P>> (n)
#define pq(n) priority_queue<int> (n)
using namespace std;

int len(int n){
    if(n==0){
        return 1;
    }
    return len(n-1)*2+3;
}
int pti(int n){
    if(n==0){
        return 1;
    }
    return pti(n-1)*2+1;
}
bool koe(int n,int x){
    if(x>len(n-1)+1){
        return true;
    }
    return false;
}



signed main(){
    int n,x;
    cin >> n >> x;
    if(x==1){
        cout << 0;
        return 0;
    }
    int ans = 0;
    for(int i = n;i > 0;i--){
        if(koe(i,x)){
            x -= len(i-1)+2;
            ans += pti(i-1)+1;
        }
        else{
            x--;
        }
    }
    if(x>0){
        ans ++;
    }
    cout << ans << endl;

    return 0;
}

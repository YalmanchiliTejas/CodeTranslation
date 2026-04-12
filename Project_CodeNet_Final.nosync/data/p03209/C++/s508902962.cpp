#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1 << 30;
#define FOR(i,k,n) for(int i=(k);i<(n);++i)

ll a_list[55];
ll a(int k){
    if(a_list[k] != 0) return a_list[k];
    if(k == 0){a_list[k]=1;return 1;}
    else{a_list[k]=2*a(k-1)+3; return a_list[k];}
}

ll p_list[55];
ll p(int k){
    if(p_list[k] != 0) return p_list[k];
    if(k == 0){p_list[k]=1;return 1;}
    else{p_list[k]= 2*p(k-1)+1;return p_list[k];}
}

ll f(int k,ll y){
    if(k==0 && y==1) return 1;
    if(k>=1){
        if(y==1) return 0;
        if(2<=y && y<=1+a(k-1)) return f(k-1,y-1);
        if(y==2+a(k-1)) return p(k-1)+1;
        if(3+a(k-1)<=y && y<= a(k)-1) return p(k-1)+1+f(k-1,y-(a(k-1)+2));
        if(y==a(k)) return p(k);
    }
    else return -1;
}

int main(){
    FOR(i,0,55) a_list[i]=0;FOR(i,0,55) p_list[i]=0;
    int n; ll x;
    cin >> n >> x;
    ll res = 0LL;
    cout << f(n,x) << endl;
}
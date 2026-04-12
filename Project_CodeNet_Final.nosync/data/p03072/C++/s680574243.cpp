#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define clr(a,x) memset(a,x,sizeof(a))
#define SZ(x) ((int)(x).size())
#define lson rt<<1
#define rson rt<<1|1
#define pb push_back
#define fi first
#define se second
#define what_is(x) cerr<<#x<<" "<<x<<endl;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
template <typename T>
inline void _read(T& x){
    cin>>x;
}
void R(){}
template <typename T,typename... U>
void R(T&head,U&... tail){
    _read(head);
    R(tail...);
}

template <typename T>
inline void _write(const T& x){
    cout<<x<<' ';
}
void W(){cout<<endl;}
template <typename T,typename... U>
void W(const T&head,const U&... tail){
    _write(head);
    W(tail...);
}

void go();
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    go();
    return 0;
}
/****************ackun*********************/

void go(){
    int n;
    R(n);
    int ans=0;
    int mx=0;
    rep(i,1,n){
        int x;
        R(x);
        if(x>=mx){
            ans++;
        }
        mx=max(mx,x);
    }
    W(ans);
}

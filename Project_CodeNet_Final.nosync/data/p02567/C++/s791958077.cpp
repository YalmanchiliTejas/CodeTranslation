#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
using ll=long long;
template<class T,class U> inline bool chmin(T&x,U y){if(x>y){x=y;return true;}return false;}
template<class T,class U> inline bool chmax(T&x,U y){if(x<y){x=y;return true;}return false;}
#define fr(i,n) for(int i=0;i<(n);++i)
#define Fr(i,n) for(int i=1;i<=(n);++i)
#define ifr(i,n) for(int i=(n)-1;i>=0;--i)
#define iFr(i,n) for(int i=(n);i>0;--i)

int mx(int x,int y){return max(x,y);}
int e(){return -1;}
int b;
bool f(int x){
    return x<b;
}
void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    for(auto&i:a) cin>>i;
    segtree<int,mx,e> sg(a);
    {
        int t,x,v;
        fr(_,q){
            cin>>t>>x>>v;
            switch(t){
                case 1:
                    sg.set(x-1,v);
                    break;
                case 2:
                    cout<<sg.prod(x-1,v)<<'\n';
                    break;
                default:
                    b=v;
                    cout<<sg.max_right<f>(x-1)+1<<'\n';
            }
        }
    }
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    solve();
}
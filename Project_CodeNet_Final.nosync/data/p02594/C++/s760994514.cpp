#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
#include<deque>
#include<map>
#include<stack>
#include<set>
#include<utility>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXN=100000;
const int MAXE=100000;
const int MAXV=10000;
const ll INF=2e18;
const ll MOD=1e9+7;

struct segtree{
    vector<ll> dat;
    int size;
    segtree(int n):dat(2*n-1,(1LL<<31)-1),size(n){};
    void update(int i,ll a){
        i+=this->size-1;
        dat[i]=a;
        while(i>0){
            i=(i-1)/2;
            dat[i]=min(dat[i+2+1],dat[i*2+2]);
        }
    }
    ll query(int a,int b){
        return querysub(a,b,0,0,this->size);
    }
    ll querysub(int a,int b,int k,int l,int r){
        if(r<=a||b<=l) return (1LL<<31)-1;
        else if(a<=l&&r<=b) return dat[k];
        else{
            ll vl=querysub(a,b,k*2+1,l,(l+r)/2);
            ll vr=querysub(a,b,k*2+2,(l+r)/2,r);
            return min(vl,vr);
        }
    }
};

int main(){
    int x;cin>>x;
    cout<<(x>=30?"Yes":"No")<<endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

//C++14 (GCC 5.4.1)

#define LLINF (1LL<<60)
typedef long long ll;
typedef pair<ll,ll> RR;
#define mod 1000000007

#define repd(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define rrepd(i,a,b) for(int i=(a);i>=(b);i--)

template<typename T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<typename T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

template < typename T > inline string toString( const T &a ) { ostringstream oss; oss << a; return oss.str(); }

#define dbg_v1(i,V) do{cout<<"-v1----\n";rep(i,V.size())cout<<" "<<i<<"\t:"<<V[i]<<endl;cout<<endl;}while(0)
#define dbg_v2(i,k,V) do{cout<<"-v2----\n";rep(i,V.size()){rep(k,V[0].size())cout<<" "<<V[i][k];cout<<endl;}}while(0)

ll pt[51]={0},so[51]={0};

ll band(int lv,ll &k){
    ll ans=0;
    if(lv==0){
        k--;
        return 1;
    }
    k--;
    if(k<=0) return ans;

    if(so[lv-1]<k){
        k-=so[lv-1];
        ans+=pt[lv-1];
    }else{
        ans+=band(lv-1,k);
        if(k<=0) return ans;
    }
    
    ans++;
    k--;
    if(k<=0) return ans;

    if(so[lv-1]<k){
        k-=so[lv-1];
        ans+=pt[lv-1];
    }else{
        ans+=band(lv-1,k);
        if(k<=0) return ans;
    }

 //   printf("B");
    k--;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);//stdoutとcoutの同期解除
    cin.tie(nullptr);//cinとcoutの同期解除
    
    int N;
    ll K;
    cin >>N>>K;
    //-----------------------------------
    pt[0]=1;
    so[0]=1;
    repd(i,1,51){
        pt[i]=pt[i-1]*2+1;
        so[i]=so[i-1]*2+3;
    }
    ll ans=0,i=0;
    ans=band(N,K);


    cout << ans <<endl;
    return (0);
}
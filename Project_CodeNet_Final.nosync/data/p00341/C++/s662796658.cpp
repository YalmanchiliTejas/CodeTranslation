#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define pb push_back
#define fi first
#define se second
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

signed main(){
    int e[12];rep(i,12)cin>>e[i];
    sort(e,e+12);

    for(int i=0;i<12;i+=4){
        for(int j=0;j<4;j++){
            if(e[i]!=e[i+j]){
                cout<<"no"<<endl;
                return 0;
            }
        }
    }
    cout<<"yes"<<endl;
    return 0;
}
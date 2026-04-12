#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second
typedef pair<ll,ll> P;
using VP = vector<P>; using VVP = vector<VP>;
using VI = vector<ll>; using VVI = vector<VI>; using VVVI = vector<VVI>;
const int inf=1e9+7;
const ll INF=1LL<<61;
const ll mod=1e9+7;

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

VI d(6);

void change(int i,int j,int k,int l){
    i--; j--; k--; l--;
    int tem=d[i];
    d[i]=d[j];
    d[j]=d[k];
    d[k]=d[l];
    d[l]=tem;
}

int main(){
    int i,j;
    while(1){
        int n;
        cin>>n;
        if(n==0) return 0;
        d={1,2,3,4,5,6};
        int sum=1;
        for(i=0;i<n;i++){
            string s;
            cin>>s;
            switch(s[0]){
                case 'N': change(1,2,6,5); break;
                case 'E': change(1,4,6,3); break;
                case 'W': change(1,3,6,4); break;
                case 'S': change(1,5,6,2); break;
                case 'R': change(2,3,5,4); break;
                case 'L': change(2,4,5,3); break;
            }
            sum+=d[0];
            //cout<<d[0]<<endl;
        }
        cout<<sum<<endl;
    }

}

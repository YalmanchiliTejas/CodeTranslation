#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

//0 1 2 3
//S H D C
int conv_s(char s){
    if(s=='S')return 0;
    if(s=='H')return 1;
    if(s=='D')return 2;
    return 3;
}

//0 ... 12
//2 3 ... 9 10 11 12 13 1
int conv_n(char n){
    if(isdigit(n))return n-'0'-2;
    if(n=='T')return 8;
    if(n=='J')return 9;
    if(n=='Q')return 10;
    if(n=='K')return 11;
    return 12;
}

int T;
int n[4][13],s[4][13];

signed main(){
    char hoge;
    while(cin>>hoge,hoge!='#'){
        T=conv_s(hoge);
        rep(i,4)rep(j,13){
            char x,y;
            cin>>x>>y;
            n[i][j]=conv_n(x);
            s[i][j]=conv_s(y);
        }

        int point[2]={0};
        int par=0;
        rep(t,13){
            int k[4]={0};
            k[s[par][t]]=1;
            k[T]=2;
            pint st[4];
            rep(i,4)st[i]=pint(k[s[i][t]]*13+n[i][t],i);
            sort(st,st+4);
            par=st[3].se;
            point[par&1]++;
        }
        if(point[0]>point[1])cout<<"NS "<<point[0]-6<<endl;
        else cout<<"EW "<<point[1]-6<<endl;
    }
    return 0;
}
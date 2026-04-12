#include <bits/stdc++.h>
#define ll long long
#define INF 1000000005
#define MOD 1000000007
#define EPS 1e-10
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define srep(i,s,t) for(int i=(int)(s);i<(int)(t);++i)
#define each(a,b) for(auto& (a): (b))
#define all(v) (v).begin(),(v).end()
#define len(v) (int)(v).size()
#define zip(v) sort(all(v)),v.erase(unique(all(v)),v.end())
#define cmx(x,y) x=max(x,y)
#define cmn(x,y) x=min(x,y)
#define fi first
#define se second
#define pb push_back
#define show(x) cout<<#x<<" = "<<(x)<<endl
#define spair(p) cout<<#p<<": "<<p.fi<<" "<<p.se<<endl
#define sar(a,n) cout<<#a<<":";rep(pachico,n)cout<<" "<<a[pachico];cout<<endl
#define svec(v) cout<<#v<<":";rep(pachico,v.size())cout<<" "<<v[pachico];cout<<endl
#define svecp(v) cout<<#v<<":";each(pachico,v)cout<<" {"<<pachico.first<<":"<<pachico.second<<"}";cout<<endl
#define sset(s) cout<<#s<<":";each(pachico,s)cout<<" "<<pachico;cout<<endl
#define smap(m) cout<<#m<<":";each(pachico,m)cout<<" {"<<pachico.first<<":"<<pachico.second<<"}";cout<<endl

using namespace std;

typedef pair<int,int> P;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<P> vp;
typedef vector<string> vs;

const int MAX_N = 10005;

int a1[MAX_N], a2[MAX_N], b1[MAX_N], b2[MAX_N], d[MAX_N];

inline int add(int x,int y)
{
    return (x + y)%MOD;
}

inline int sub(int x,int y)
{
    return (x+MOD-y)%MOD;
}

inline int mul(int x,int y)
{
    return (ll)x*y%MOD;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    string a,b,c;
    cin >> a >> b >> c;
    d[0] = 1;
    rep(i,len(b)){
        d[i+1] = mul(d[i],10);
    }
    rep(i,len(b)){
        b1[i+1] = add(mul(b1[i],10),b[i]-'0');
    }
    rrep(i,len(b)){
        b2[i] = add(mul(b[i]-'0',d[len(b)-1-i]),b2[i+1]);
    }
    rep(i,len(a)){
        a1[i+1] = add(mul(a1[i],10),a[i]-'0');
    }
    rrep(i,len(a)){
        a2[i] = add(mul(a[i]-'0',d[len(a)-1-i]),a2[i+1]);
    }
    ll B = 0;
    rep(i,len(b)-len(c)+1){
        if(c == "0"){
            if(i == 0){
                B = 1;
            }else{
                if(b[i] == '0'){
                    B = add(B,add(mul(sub(b1[i],1),d[len(b)-len(c)-i]),add(b2[i+len(c)],1)));
                }else{
                    B = add(B,mul(b1[i],d[len(b)-len(c)-i]));
                }
            }
            continue;
        }
        bool flag = true;
        rep(j,len(c)){
            if(b[i+j] < c[j]){
                flag = false;
                B = add(B,mul(b1[i],d[len(b)-len(c)-i]));
                break;
            }else if(b[i+j] > c[j]){
                flag = false;
                B = add(B,mul(add(b1[i],1),d[len(b)-len(c)-i]));
                break;
            }
        }
        if(flag) B = add(B,add(mul(b1[i],d[len(b)-len(c)-i]),add(b2[i+len(c)],1)));
    }
    ll A = 0;
    rep(i,len(a)-len(c)+1){
        if(c == "0"){
            if(i == 0){
                A = 1;
            }else{
                if(a[i] == '0'){
                    A = add(A,add(mul(sub(a1[i],1),d[len(a)-len(c)-i]),add(a2[i+len(c)],1)));
                }else{
                    A = add(A,mul(a1[i],d[len(a)-len(c)-i]));
                }
            }
            continue;
        }
        bool flag = true;
        rep(j,len(c)){
            if(a[i+j] < c[j]){
                flag = false;
                A = add(A,mul(a1[i],d[len(a)-len(c)-i]));
                break;
            }else if(a[i+j] > c[j]){
                flag = false;
                A = add(A,mul(add(a1[i],1),d[len(a)-len(c)-i]));
                break;
            }
        }
        if(flag) A = add(A,add(mul(a1[i],d[len(a)-len(c)-i]),add(a2[i+len(c)],1)));
    }
    ll C = 0;
    rep(i,len(a)-len(c)+1){
        if(c == "0"){
            C += (a[i] == c[0]);
            continue;
        }
        bool flag = true;
        rep(j,len(c)){
            if(a[i+j] != c[j]){
                flag = false;
                break;
            }
        }
        C += flag;
    }
    cout << add(sub(B,A),C) << "\n";
    return 0;
}

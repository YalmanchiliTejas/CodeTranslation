#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define P pair<int,int>
#define fi first
#define se second
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1000000000000000000
#define MOD 1000000007
#define all(v) v.begin(),v.end()
#define pb push_back
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
int kaijo[2000010];
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
int lcm(int a,int b){
    return a/gcd(a,b)*b;
}
bool prime(int a){
    if(a==1)return false;
    for(int i=2;i*i<=a;i++){
        if(a%i==0)return false;
    }
    return true;
}
void init_fact(){
    kaijo[0]=1;
    for(int i=1;i<=2000000;i++){
        kaijo[i]=kaijo[i-1]*i;
        kaijo[i]%=MOD;
    }
}
int modpow(int a,int b){
    if(b==0)return 1;
    if(b%2)return modpow(a,b-1)*a%MOD;
    int memo=modpow(a,b/2);
    return memo*memo%MOD;
}
int comb(int a,int b){
    if(!kaijo[0])init_fact();
    return kaijo[a]*modpow(kaijo[a-b],MOD-2)%MOD*modpow(kaijo[b],MOD-2)%MOD;
}
int inv(int x){
    x=modpow(x,MOD-2);
    return x;
}
bool kosa(double ax,double ay,double bx,double by,double cx,double cy,double dx,double dy){
    double ta=(cx-dx)*(ay-cy)+(cy-dy)*(cx-ax);
    double tb=(cx-dx)*(by-cy)+(cy-dy)*(cx-bx);
    double tc=(ax-bx)*(cy-ay)+(ay-by)*(ax-cx);
    double td=(ax-bx)*(dy-ay)+(ay-by)*(ax-dx);
    return tc*td<0&&ta*tb<0;
}
string n;
int k,m;
int f(int i,int x){
    if(x==0)return 0;
    if(i>=m)return 0;
    int res=0;
    if(n[i]=='0'){
        res+=9*comb(m-i-1,x-1)*pow(9,x-1);
        return res+f(i+1,x);
    }
    else{
        res+=(9-(n[i]-'0'))*comb(m-i-1,x-1)*pow(9,x-1);
        return res+f(i+1,x-1);
    }
}
signed main(){
    cin>>n>>k;
    m=n.size();
    if(m<k){
        cout<<0<<endl;
        return 0;
    }
    init_fact();
    int ans=comb(m,k)*pow(9,k);
    ans-=f(0,k);
    cout<<ans<<endl;
    return 0;
}
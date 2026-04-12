#include <bits/stdc++.h>

#define ll long long
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) for(int i=0;i<(n);++i)
#define debug(x) cerr<<#x<<": "<<x<<'\n'

using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

template<class T=int>
T in(){T x;cin>>x;return (x);}
template<class T>
void print(T& x){cout<<x<<'\n';}

const int MOD =(int)1e9+7;
const int MAX =510000;

ll fac[MAX],finv[MAX],inv[MAX];
void COMint(){
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for(int i=2;i<MAX;i++){
        fac[i]=fac[i-1]*i%MOD;
        inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
        finv[i]=finv[i-1]*inv[i]%MOD;
    }
}
ll COM(int n,int k){
    if(n<k) return 0;
    if(n<0||k<0)return 0;
    return fac[n]*(finv[k]*finv[n-k]%MOD)%MOD;
}

ll gcd(ll a,ll b){
    if(b==0)return a;
    if(a>b){
        swap(a,b);
    }
    return gcd(a,b%a);
}
ll lcm(ll a,ll b){
    ll g;g=gcd(a,b);
    return a*b/g;
}
string kasanari(string s1,string s2){
    vector<char> s1_c;
    vector<char> s2_c;
    REP(i,s1.size()){
        s1_c.push_back(s1[i]);
    }
    REP(i,s2.size()){
        s2_c.push_back(s2[i]);
    }
    sort(s1_c.begin(),s1_c.end());
    sort(s2_c.begin(),s2_c.end());
    string ans;ans="";
    int k=0;
    REP(i,s1_c.size()){
        for(int j=k;j<s2_c.size();j++){
            if(s1_c[i]==s2_c[j]){
                ans.push_back(s1_c[i]);
                k=j+1;
                break;
            }
        }
    }
    return ans;
}
int main() {
    //COMint();
    int n=in();
    string ans;
    string s=in<string>();
    vector<char> s_c;
    if(n==1){
        REP(i,s.size()){
            s_c.push_back(s[i]);
        }
        sort(s_c.begin(),s_c.end());
        REP(i,s_c.size()){
            ans.push_back(s_c[i]);
        }
        cout<<ans<<endl;
        return 0;
    }
    string s_next;
    cin>>s_next;
    ans=kasanari(s,s_next);
    REP(i,n-2){
        cin>>s_next;
        ans=kasanari(ans,s_next);
    }
    cout<<ans<<endl;
    return 0;
}
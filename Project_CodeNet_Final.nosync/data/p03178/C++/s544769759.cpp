#include<bits/stdc++.h>
using namespace std;

#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define MP make_pair
#define pb push_back
#define x first
#define y second
#define all(c) c.begin(),c.end()
#define int long long
#define fr(i,j,x) for(int i=j;i<x;i++)
#define rep(i,j,x) for(int i=j;i<=x;i++)
//#define endl '\n'
#define vi vector<int>
#define pii pair<int,int>
const int mod=1e9+7;
const int N=1e5+10;

string to_string(string s) { return '"' + s + '"';}
string to_string(char s) { return string(1, s);}
string to_string(const char* s) { return to_string((string) s);}
string to_string(bool b) { return (b ? "true" : "false");}
template <typename A> string to_string(A);
template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename A> string to_string(A v) {bool f = 1; string r = "{"; for (const auto &x : v) {if (!f)r += ", "; f = 0; r += to_string(x);} return r + "}";}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {cerr << " " << to_string(H); debug_out(T...);}
#define pr(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

string getBase(int x,int b){
    string ans;
    while(x){
        ans+=('0'+x%b);
        x/=b;
    }
    return ans;
}

string L,R;
int dp[10010][2][2][101],D;

int getAns(int level,int tlo,int thi,int rem){
    if(level>=L.size()){
        if(rem==0)return 1;
        return 0;
    }
    if(dp[level][tlo][thi][rem]==-1){
        int blo=0;
        int bhi=9;
        if(tlo){
            blo=L[level]-'0';
        }
        if(thi){
            bhi=R[level]-'0';
        }

        int ans=0;
        for(int i=blo;i<=bhi;i++){
            int ntlo=tlo;
            int nthi=thi;
            if(i>L[level]-'0'){
                ntlo=0;
            }
            if(i<R[level]-'0'){
                nthi=0;
            }

            ans+=getAns(level+1,ntlo,nthi,(rem+i)%D);
            ans%=mod;
            
        }
        dp[level][tlo][thi][rem]=ans;
    }
    return dp[level][tlo][thi][rem];
}

void solve(){
    L="1";
    cin>>R;
    reverse(all(R));
    // L=getBase(l,2);
    // R=getBase(r,2);
    while(L.length()<R.length()){
        L+='0';
    }
    while(R.length()<L.length()){
        R+='0';
    }
    reverse(all(L));
    reverse(all(R));
    //pr(L,R);
    cin>>D;
    memset(dp,-1,sizeof(dp));
    cout<<getAns(0,1,1,0)<<endl;
}


int32_t main()
{
    SPEED;
    int T=1;
    //cin>>T;
    int t1=1;
    while(true)
    {  
        solve(); 
        t1++;
        if(t1>T)
            break;
    }
}   
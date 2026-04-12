#include<bits/stdc++.h>
#define Int int64_t
#define ll long long
#define pb push_back
using namespace std;
const Int MAXN=200005;
const int ALPHA=26;

Int N,K,M;
Int X,Y,Z;Int C;
vector<Int> ID;
vector<Int> SZ;
string S;
int find(int x){
    if(ID[x]==x) return x;
    return find(ID[x]);
}
void Union(int x,int y){
    x=find(x);y=find(y);
    if(x==y) return;
    if(SZ[x]>SZ[y]){
        ID[y]=x;
        SZ[x]+=SZ[y];
    }
    else{
        ID[x]=y;
        SZ[y]+=SZ[x];
    }
    return;
}
string common_prefix(string s,string t){
    string ans="";
    for(int i=0;i<min(s.length(),t.length());++i){
        if(s[i]==t[i]) ans.pb(s[i]);
        else break;
    }
    return ans;
}
string LCP(vector<string> A,int l,int r){
    if(l>r) return "";
    if(l==r) return A[l];
    int mid=(l+r)/2;
    string left=LCP(A,l,mid);
    string right=LCP(A,mid+1,r);
    return common_prefix(left,right);
}

long long ModExpo(long long x,unsigned long long y,long long M){
    Int ans=1;
    ans=(long long)ans;
    
    while(y>0){
        if(y&1) ans=((ans%M)*(x%M))%M;
        y>>=1LL;
        x=((x%M)*(x%M))%M;
    }
    return ans%M;
}
Int LCM(Int x,Int y){
    return (x*y)/__gcd(x,y);
}

using D=long double;
vector<Int> A,B;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);
    int t;
    t=1;
    while(t--){
    cin>>N;
    cout<<(N>=30 ? "Yes\n":"No\n");
    }
}
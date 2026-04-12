#include <bits/stdc++.h>
#define mod 1000000007
#define fr first
#define val second
#define N 100000000
#define fo(i,m,n) for(int i=m;i<n;i++)
#define M 7
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
using ll=long long;
using ul=unsigned long long;
using pii=pair<int,int>;
using vvi=vector<vector<int>>;
using vi=vector<int>;
using pll=pair<ll,ll>;
using vsi=vector<set<int>>;
using vll=vector<ll>;

ll power(ll a,ll n){
    ll j=0;
    ll x=1;
    while(1ll<<j<=n){
        if(1ll<<j&n)
            x=(x*a)%mod;

        a=a*a%mod;
        j++;
    }

    return x;
}

int gcd(int a,int b){
    if(b==0)
        return a;
    else
        return gcd(b,a%b);

}

int lb(vi &a,int x){
    int n=a.size();
    int l=0;
    int r=n-1;
    int ind=-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(x>=a[mid]){
            l=mid+1;
            ind=mid;
        }
        else
            r=mid-1;

    }

    return ind+1;

}

int up(vll &a,ll x){
    int n=a.size();
    int l=0;
    int r=n-1;
    int ind=-1;

    while(l<=r){
        int mid=(l+r)/2;

        if(a[mid]>x){
            l=mid+1;
            ind=mid;
        }
        else
            r=mid-1;

    }

    return ind;
}

ll max(ll a,ll b){
    if(a>b)
        return a;
    else
        return b;

}

ll min(ll a, ll b){
    if(a>b)
        return b;
    else
        return a;

}
template<typename T>
void pra(T a[],int n){
    fo(i,0,n)
            cout<<a[i]<<' ';
    cout<<endl;

}

ifstream input;
ofstream output;
int t;
const ll inf=1e16;
int cs;
int tcs;
void build(vll &F,int ind,int tl,int tr,vll &st){

    if(tl==tr)
        st[ind]=F[tl];
    else{
        int mid=(tl+tr)/2;
        build(F,2*ind+1,tl,mid,st);
        build(F,2*ind+2,mid+1,tr,st);
        st[ind]=min(st[2*ind+1],st[2*ind+2]);
    }

}

void update(int j,ll nv,int ind,int tl,int tr,vll &st){

    if(j<tl||j>tr)
        return;
    else if(tl==tr)
        st[ind]=nv;
    else{
        int mid=(tl+tr)/2;
        update(j,nv,2*ind+1,tl,mid,st);
        update(j,nv,2*ind+2,mid+1,tr,st);
        st[ind]=min(st[2*ind+1],st[2*ind+2]);
    }

}


ll query(int ind,int tl,int tr,int l,int r,vll &st){
    int mid=(tl+tr)/2;
    if(r<tl||l>tr)
        return inf;
    else if(tl==l&&tr==r)
        return st[ind];
    else
        return min(query(2*ind+1,tl,mid,l,min(mid,r),st),query(2*ind+2,mid+1,tr,max(mid+1,l),r,st));

}

int main(){
    int x;
    cin>>x;

    if(x>=30)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

}

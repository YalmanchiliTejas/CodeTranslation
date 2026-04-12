#include<bits/stdc++.h>
#include<stdio.h>
#include<string.h>
using namespace std;
#define ll  long long
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define pii pair<ll,ll>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define rep(i,t,n) for(int i=t;i<n;i++)
#define nd "\n"
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>




/*ll power(ll x,ll t){
if(t<=0){
    return 1;
}
ll y=(power(x,t/2));
y=(y*y)%ma;
if(t%2)
    y=(y*x)%ma;
return y;

}*/
/*ll ph[100001];
void E_phi(int n){

ph[0]=0;
ph[1]=1;
for(int i=2;i<=n;i++){
    ph[i]=i;
}
for(int i=2;i<=n;i++){
    if(ph[i]==i){
        for(int j=i;j<=n;j+=){
            ph[j]-=ph[j]/i;
        }
    }
}


}*/
/*string s,t;
vector<int>  z_fun(string s){

int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}*/

/*struct st{
ll sum,pre,suf,ans;
st(){}
st(ll k){
ans=k,pre=k,suf=k,sum=0;
}

};
ll t[4*200001+4];
ll a[200001];
ll lazy[4*200001+4];
ll mx=1e14;



void push(int ind){
int l=2*ind+1,r=2*ind+2;
t[l]+=lazy[ind];
t[r]+=lazy[ind];
lazy[l]+=lazy[ind];
lazy[r]+=lazy[ind];
lazy[ind]=0;

}

void build(int ind,int l,int r){
if(l==r){
    t[ind]=a[l];
return;
}
int mid=(l+r)/2;
build(2*ind+1,l,mid);
build(2*ind+2,mid+1,r);

  t[ind] =min(t[ind*2+1] , t[ind*2+2]);



}
ll query(int ind,int l,int r,int p,int q){

if(l>q || r<p )
    return mx;
    int mid=(l+r)/2;

if(l>=p && r<=q )
    {
      return t[ind];
    }
    push(ind);
ll x=query(2*ind+1,l,mid,p,q);
ll y=query(2*ind+2,mid+1,r,p,q);


return min(x,y);
}

void update(int ind,int l,int r,int p,int q,int val){
if(l>q || r<p )
    return;

if(l>=p && r<=q )
    {
      t[ind]+=val;
      lazy[ind]+=val;
      return;
    }
push(ind);
int mid=(l+r)/2;
    update(2*ind+1,l,mid,p,q,val);
     update(2*ind+2,mid+1,r,p,q,val);
    t[ind]=min(t[2*ind+1],t[2*ind+2]);



}


ll mod(ll a){
if(a>=0)
    return a;
else return -a;
}
*/



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

ll ma=1e9+7;
ll ans=0;
ll x=0;
int n;
cin>>n;
ll a[n];
rep(i,0,n)
cin>>a[i];
for(int i=n-1;i>=0;i--){
    ans=(ans+(a[i]*x)%ma)%ma;
    x=(x+a[i])%ma;
}
cout<<ans<<nd;

    }


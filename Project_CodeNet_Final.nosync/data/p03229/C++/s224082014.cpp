#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<limits>
#include<iomanip>
#include<cmath>
#include<climits>
using namespace std;

#define rp(i,n) for(int i=0;i<n;i++)
#define rep(i,m,n) for(int i=m;i<=n;i++)
#define llrp(i,n) for(long long i=0;i<n;i++)
#define llrep(i,m,n) for(long long i=m;i<=n;i++)
#define sort(a) sort(a.begin(),a.end())
#define reverse(a) reverse(a.begin(),a.end())
#define pb push_back
#define elif else if
#define vcin(a); rp(i,a.size()){cin>>a[i];}
#define vcout(a); rp(i,a.size()){cout<<a[i]<<endl;}
#define allchar(c) for(char c='a';c<='z';c++)

typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef long long ll;
typedef string S;
typedef pair<int,int> P;
typedef queue<int> qi;

const int mod=1e9+7;

ll modpow(ll a,ll b,ll p){
    if(b==0){
        return 1;
    }elif(b%2==0){
        return modpow((a*a)%p,b/2,p);
    }else{
        return (a*modpow(a,b-1,p))%p;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vll a(n);
    vcin(a);
    sort(a);
    ll ans=0;
    if(a.size()%2==0){
        rp(i,n){
            if(i<n/2){
                ans-=a[i]*2;
            }else{
                ans+=a[i]*2;
            }
        }
        ans-=a[n/2];
        ans+=a[n/2-1];
    }else{
        rp(i,n){
            if(i<n/2){
                ans-=a[i]*2;
            }elif(i>n/2){
                ans+=a[i]*2;
            }
        }
        ll c=ans,d=ans;
        c-=a[n/2];
        c+=a[n/2-1];
        d+=a[n/2];
        d-=a[n/2+1];
        ans=max(c,d);
    }
    cout << ans << endl;
    return 0;
}

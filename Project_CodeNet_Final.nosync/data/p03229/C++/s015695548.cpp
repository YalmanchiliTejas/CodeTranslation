#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define len(v) ll(v.size())
#define fi first
#define se second

template <class T>
void cout_vec(const vector<T> &vec){
  for(auto itr:vec) cout<<itr<<' ';
  cout<<endl;
}

typedef pair<ll,ll> P;
const ll mod=1e9+7;
const ll inf=1e15;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<ll> a(n);
    deque<ll> ans1,ans2;
    rep(i,n) cin>>a[i];
    sort(begin(a),end(a));
    int l=0,r=n-1,cnt=0;
    while(len(ans1)!=n){
      if(ans1.empty()){
        ans1.push_front(a[l]);
        l++;
      }else{
        if(cnt%2==0){
          if(len(ans1)==n-1){
            if(abs(ans1.front()-a[r])<abs(ans1.back()-a[r])) ans1.push_back(a[r]);
            else ans1.push_front(a[r]);
          }else{
            ll x=a[r],y=a[r-1];
            r-=2;;
            if(abs(ans1.front()-x)+abs(ans1.back()-y)<abs(ans1.front()-y)+abs(ans1.back()-x)){
              ans1.push_front(y);
              ans1.push_back(x);
            }else{
              ans1.push_front(x);
              ans1.push_back(y);
            }
          }
          cnt++;
        }else{
          if(len(ans1)==n-1){
            if(abs(ans1.front()-a[l])<abs(ans1.back()-a[l])) ans1.push_back(a[l]);
            else ans1.push_front(a[l]);
          }else{
            ll x=a[l],y=a[l+1];
            l+=2;
            if(abs(ans1.front()-x)+abs(ans1.back()-y)<abs(ans1.front()-y)+abs(ans1.back()-x)){
              ans1.push_front(y);
              ans1.push_back(x);
            }else{
              ans1.push_front(x);
              ans1.push_back(y);
            }
          }
          cnt++;
        }
      }
    }
    l=0,r=n-1,cnt=0;
    while(len(ans2)!=n){
      if(ans2.empty()){
        ans2.push_front(a[r]);
        r--;
      }else{
        if(cnt%2==1){
          if(len(ans2)==n-1){
            if(abs(ans2.front()-a[r])<abs(ans2.back()-a[r])) ans2.push_back(a[r]);
            else ans2.push_front(a[r]);
          }else{
            ll x=a[r],y=a[r-1];
            r-=2;
            if(abs(ans2.front()-x)+abs(ans2.back()-y)<abs(ans2.front()-y)+abs(ans2.back()-x)){
              ans2.push_front(y);
              ans2.push_back(x);
            }else{
              ans2.push_front(x);
              ans2.push_back(y);
            }
          }
          cnt++;
        }else{
          if(len(ans2)==n-1){
            if(abs(ans2.front()-a[l])<abs(ans2.back()-a[l])) ans2.push_back(a[l]);
            else ans2.push_front(a[l]);
          }else{
            ll x=a[l],y=a[l+1];
            l+=2;
            if(abs(ans2.front()-x)+abs(ans2.back()-y)<abs(ans2.front()-y)+abs(ans2.back()-x)){
              ans2.push_front(y);
              ans2.push_back(x);
            }else{
              ans2.push_front(x);
              ans2.push_back(y);
            }
          }
          cnt++;
        }
      }
    }
    ll cnt1=0,cnt2=0;;
    rep(i,n-1) cnt1+=abs(ans1[i]-ans1[i+1]);
    rep(i,n-1) cnt2+=abs(ans2[i]-ans2[i+1]);
    cout<<max(cnt1,cnt2)<<endl;
}
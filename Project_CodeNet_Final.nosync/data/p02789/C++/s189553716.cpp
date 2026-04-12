#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll=long long;
using vec=vector<ll>;
using vect=vector<double>;
using Graph = vector<vector<ll>>;
#define loop(i,n) for(ll i=0;i<n;i++)
#define Loop(i, m, n) for(ll i = m;i < n;i++)
#define pool(i,n) for(ll i=n;i>=0;i--)
#define Pool(i, m, n) for(ll i=n;i>=m;i--)
#define MAX 99999999999ll
#define MIN -99999999999ll
#define setbit bitset<8>
#define flagcount __builtin_popcount
#define flag(x) (1<<x)
#define flagadd(bit,x) bit|=flag(x)
#define flagpop(bit,x) bit&=~flag(x) 
#define flagon(bit,i) bit&flag(i)
#define flagoff(bit,i) !(bit & (1<<i))
#define all(v) v.begin(),v.end()
#define low2way(v,x) lower_bound(all(v),x)
#define high2way(v,x) upper_bound(all(v),x)
#define count2way(v,x) high2way(v,x)-low2way(v,x)
#define lower(v,x) low2way(v,x)-v.begin() //1番左が0、もし見つから無いならｎを出力
#define higher(v,x) high2way(v,x)-v.begin()-1 //1番左が0、もし見つからないならn-1を出力（注意）
#define putout(a) cout<<a<<endl
#define putout2(a,b) putout(a);putout(b)
#define putout3(a,b,c) putout(a);putout(b);putout(c)
#define putout4(a,b,c,d) putout(a);putout(b);putout(c);putout(d)
#define putout5(a,b,c,d,e) putout(a);putout(b);putout(c);putout(d);putout(e)
#define Gput(a,b) G[a].push_back(b)
#define cin1(a) cin>>a
#define cin2(a,b) cin>>a>>b
#define cin3(a,b,c) cin>>a>>b>>c
#define cin4(a,b,c,d) cin>>a>>b>>c>>d
#define cin5(a,b,c,d,e) cin>>a>>b>>c>>d>>e
#define sum(v) accumulate(all(v), 0ll)
#define gcd(x,y) __gcd(x,y)
ll ctoi(char c){
	if(c>='0'&&c<='9'){
		return c-'0';
	}
	return 0;
}
ll lcm(ll x,ll y){
  ll z=gcd(x,y);
  return x*y/z;
}
ll primejudge(ll n){
  if(n<2)return 0;
  else if(n==2)return 1;
  else if(n%2==0)return 0;
  double sqrtn=sqrt(n);
  Loop(i,3,sqrtn+1){
     if(n%i==0){
        return 0;
     }
     i++;
  }
  return 1;
}
int main() {
  cout << fixed << setprecision(30);
  ll a,b;
  cin>>a>>b;
  if(a==b)putout("Yes");
  else putout("No");
}

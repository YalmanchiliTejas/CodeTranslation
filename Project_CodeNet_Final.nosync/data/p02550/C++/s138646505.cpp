//#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#include<algorithm>//next_permutation
#define rep(i,n) for (int i = 0;i < (n);i++)
#define all(v) v.begin(),v.end()
#define dec(n) cout << fixed << setprecision(n);
#define large "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define small "abcdefghijklmnopqrstuvwxyz"
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using vvl = vector<vl>;

ll gcd(ll a,ll b){
  if(b == 0) return a;
  return gcd(b , a % b);
}

const ll MOD = 1000000007;
const ll MAX = 2000001;

ll mod(ll a){
  return a % MOD;
}

ll lcm(ll a,ll b){
  return (a*b)/gcd(a,b);
}


int main(){
  ll n,x,m; cin >> n >> x >> m;
  ll nd = n;
  
  queue<ll> q; set<ll> came;
  bool flag = true;
  
  ll ans = 0; ll doubling = 0;
  
  while(flag and n != 0){
    if(came.count(x)){
      flag = false;
      doubling = x;
      ans += x;
      n--;
      break;
    }
    else if(x == 0){
      cout << ans << endl;
      return 0;
    }
    
    came.insert(x);
    q.push(x);
    
    ans += x;
    n--;
    x = ((x*x) % m);
  }
  
  bool flag2 = true; ll loopcnt = 0; ll loopsum = 0;
  bool loopin = false;
  
  while(flag2){
    if(q.front() == doubling){
      if(!loopin){
        loopin = true;
        loopcnt++;
        loopsum += q.front();
        q.push(q.front());
        q.pop();
      }
      else{
        //loopcnt++;
        //loopsum += q.front();
        flag2 = false;
        //q.push(q.front());
        q.pop();
        break;
      }
    }
    else if(!loopin){
      q.pop();
    }
    else{
      loopsum += q.front();
      loopcnt++;
      q.push(q.front());
      q.pop();
    }
  }
      
  
  if(n == 0){
    cout << ans << endl;
    return 0;
  }
  
  //cout << loopcnt << ' ' << loopsum << endl;
  
  ans += (n/loopcnt) * loopsum;
  n = n % loopcnt;
  
  while(n > 0){
    ans += q.front();
    q.push(q.front());
    q.pop();
    n--;
  }
  
  cout << ans << endl;
  
}
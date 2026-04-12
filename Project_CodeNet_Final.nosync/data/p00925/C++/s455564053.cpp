#include<bits/stdc++.h>
#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define BITLE(n) (1LL<<((ll)n))
#define SHIFT_LEFT(n) (1LL<<((ll)n))
#define SUBS(s,f,t) ((s).substr((f)-1,(t)-(f)+1))
#define ALL(a) (a).begin(),(a).end()
using namespace std;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s;
  cin>>s;
  ll n = s.size();
  ll num;cin>>num;

  ll lr = 0;
  bool plus = true;
  for(int i=0;i<n;i++){
    if(i%2){
      if(s[i] == '+')plus = true;
      else plus = false;
    }else{
      if(plus)lr += (s[i]-'0');
      else lr *= (s[i]-'0');
    }
  }
  ll cl = 0;
  vi nu;
  nu.pb(s[0]-'0');
  for(int i=1;i<n;i+=2){
    if(s[i] == '+'){
      nu.pb(s[i+1]-'0');
    }else{
      nu[nu.size()-1] *= (s[i+1]-'0');
    }
  }
  //cout<<nu.size()<<endl;

  for(auto a:nu){cl+=a;}
  //cout<<cl<<" "<<lr<<endl;
  if(cl != num && lr != num){
    cout<<"I"<<endl;
  }else{
    if(cl == lr)cout<<"U"<<endl;
    else if(cl == num)cout<<"M"<<endl;
    else cout<<"L"<<endl;
  }
  return 0;
}


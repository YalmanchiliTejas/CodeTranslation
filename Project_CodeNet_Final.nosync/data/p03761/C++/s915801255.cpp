#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef pair<ll,ll> P;
#define fi first
#define se second
#define all(v) (v).begin(),v.end()
set<string> c;
const ll mod=1000000007;
const ll mod2=998244353;
const ll inf=100000000000000000;
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
map<char,ll> moji,tmp;
int main(){
  int n;
  cin>>n;
  vector<string> s(n);
  for(int i=0;i<n;i++)cin>>s.at(i);
  for(int i=0;i<s.at(0).size();i++)moji[s.at(0).at(i)]++;
  for(int i=1;i<n;i++){
      for(int j=0;j<s.at(i).size();j++){
              tmp[s.at(i).at(j)]++;
      }
      for(char c='a';c<='z';c++){
          moji[c]=min(moji[c],tmp[c]);
      }
      tmp.clear();
  }
   string ans={};
   for(char c='a';c<='z';c++){
          if(moji[c]>0){
              while(moji[c]--){
                  ans.push_back(c);
              }
          }
      }
      sort(all(ans));
      cout<<ans<<endl;
}

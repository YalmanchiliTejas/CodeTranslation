#include<bits/stdc++.h>
#define ll long long int
#define vec vector<ll>
#define mat vector<vec>

using namespace std;

const ll mod=1000000007;
const ll inf=LONG_LONG_MAX;
ll dx4[4]={1,0,-1,0};
ll dy4[4]={0,-1,0,1};
ll dx8[8]={1,0,-1,1,-1,1,0,-1};
ll dy8[8]={1,1,1,0,0,-1,-1,-1};

vec s(51);
vec t(51);

ll solve(ll a,ll b){
  if(b==0)return 0;
  if(a==1){
    if(b==1)return 0;
    else if(b<=4)return b-1;
    else return 3;
  }
  if(b<=s[a-1]+1)return solve(a-1,b-1);
  else if(b<s[a])return t[a-1]+1+solve(a-1,b-s[a-1]-2);
  else return t[a];
}

int main(){

  s[1]=5;
  for(ll i=1;i<50;i++)s[i+1]=2*s[i]+3;

  t[1]=3;
  for(ll i=1;i<50;i++)t[i+1]=2*t[i]+1;

  ll n,x;
  cin >> n >> x;
  cout << solve(n,x) << endl;
  //cout << s[50] << endl;
}

#include<bits/stdc++.h>
using namespace std;
#define inf 1000000000
#define INF 1000000000000000
#define ll long long
#define ull unsigned long long
#define M (int)(1e9+7)
#define P pair<int,int>
#define PLL pair<ll,ll>
#define FOR(i,m,n) for(int i=(int)m;i<(int)n;i++)
#define RFOR(i,m,n) for(int i=(int)m;i>=(int)n;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,n,0)
#define all(a) a.begin(),a.end()
#define IN(a,n) rep(i,n){ cin>>a[i]; }
const int vx[4] = {0,1,0,-1};
const int vy[4] = {1,0,-1,0};
#define PI 3.14159265
#define F first
#define S second
#define PB push_back
#define EB emplace_back
#define int ll
void init(){
  cin.tie(0);
  ios::sync_with_stdio(false);
}


int f(string s){
  stack<int> st;

  int i=0;
  int r=0;
  while('0'<=s[i]&&s[i]<='9'){
    r*=10;
    r+=s[i]-'0';
    i++;
  }
  st.push(r);

  while(i<s.size()){
    bool flag=false;
    if(s[i]=='+'){
      flag=true;
    }
    i++;
    r=0;
    while('0'<=s[i]&&s[i]<='9'){
      r*=10;
      r+=s[i]-'0';
      i++;
    }
    int t=st.top(); st.pop();
    if(flag)
      st.push(r+t);
    else
      st.push(r*t);
  }

  return st.top();
}


int g(string s){
  stack<int> st;
  int i=0,r=0;
  while('0'<=s[i]&&s[i]<='9'){
    r*=10;
    r+=s[i]-'0';
    i++;
  }
  st.push(r);

  while(i<s.size()){
    bool flag=false;
    if(s[i]=='*') flag=true;
    i++;
    r=0;
    while('0'<=s[i]&&s[i]<='9'){
      r*=10;
      r+=s[i]-'0';
      i++;
    }
    if(flag){
      int t=st.top(); st.pop();
      st.push(t*r);
    }else
      st.push(r);
  }

  int ans=0;
  while(!st.empty()){
    ans+=st.top();
    st.pop();
  }

  return ans;
}


main(){
  string s;
  int n;
  cin>>s;
  cin>>n;

  int a=f(s);
  int b=g(s);

  if(a==n&&b==n){
    cout<<'U'<<endl;
  }else if(a==n){
    cout<<'L'<<endl;
  }else if(b==n){
    cout<<'M'<<endl;
  }else{
    cout<<'I'<<endl;
  }
}


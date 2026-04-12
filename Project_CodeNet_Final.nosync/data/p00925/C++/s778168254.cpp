#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define repp(i, l, r) for(int i = (l); i < (r); i++)
#define per(i, n) for(int i = ((n)-1); i >= 0; i--)
#define perr(i, l, r) for(int i = ((r)-1); i >= (l); i--)
#define all(x) (x).begin(),(x).end()
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000
#define SP <<" "<<
#define CYES cout<<"Yes"<<endl
#define CNO cout<<"No"<<endl
#define CFS cin.tie(0);ios::sync_with_stdio(false)

typedef long long LL;
typedef long double LD;

int main(){
  string s;
  int ans;
  cin >> s >> ans;
  int n = s.length();
  int x,y;
  stack<int> st;
  int now=s[0]-'0';
  rep(i,(n-1)/2){
    if(s[2*i+1]=='+'){
      st.push(now);
      now=s[2*i+2]-'0';
    }else{
      now*=s[2*i+2]-'0';
    }
  }
  st.push(now);
  x=0;
  while(!st.empty()){
    x+=st.top();
    st.pop();
  }
  y=s[0]-'0';
  rep(i,(n-1)/2){
    if(s[2*i+1]=='+'){
      y+=s[2*i+2]-'0';
    }else{
      y*=s[2*i+2]-'0';
    }
  }
  if(ans==x){
    if(ans==y){
      cout << "U" << endl;
    }else{
      cout << "M" << endl;
    }
  }else{
    if(ans==y){
      cout << "L" << endl;
    }else{
      cout << "I" << endl;
    }
  }
  return 0;
}


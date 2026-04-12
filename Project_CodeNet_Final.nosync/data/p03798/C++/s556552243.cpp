#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define pb push_back
using ll = long long;
using vin=vector<int>;
using vll=vector<ll>;
using vst=vector<string>;
using P = pair<ll,ll>;
const int inf=1e9+7;
const ll INF=9e18;
template <typename T> bool chmin(T &a, const T& b){if(a > b){a = b;return true;}return false;}
template <typename T> bool chmax(T &a, const T& b){if(a < b){a = b;return true;}return false;}
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };
int n;
string s;
bool check(vin &a){
  rep(i,2,n){
    if(s[i-1]=='o'){
      if(a[i-1]==0){
        a[i]=a[i-2];
      }
      else{
        a[i]=(!a[i-2]);
      }
    }
    else{//x
      if(a[i-1]==0){
        a[i]=(!a[i-2]);
      }
      else{
        a[i]=a[i-2];
      }
    }
  }
  bool ans=1;
  //0
  if(s[0]=='o'){
    if(a[0]==0){
      if(a[n-1]!=a[1])ans=false;
    }
    else{
      if(a[n-1]==a[1])ans=false;
    }
  }
  else{
    if(a[0]==0){
      if(a[n-1]==a[1])ans=false;
    }
    else{
      if(a[n-1]!=a[1])ans=false;
    }
  }
  
  //n-1
  if(s[n-1]=='o'){
    if(a[n-1]==0){
      if(a[n-2]!=a[0])ans=false;
    }
    else{
      if(a[n-2]==a[0])ans=false;
    }
  }
  else{
    if(a[n-1]==0){
      if(a[n-2]==a[0])ans=false;
    }
    else{
      if(a[n-2]!=a[0])ans=false;
    }
  }
  
  return ans;
}

int main(){cout<<fixed<<setprecision(20);
		   //先頭二人O(n)
           cin>>n;
           cin>>s;
           bool ok=false;
           rep(i,0,4){
             vin a(n,-1);
             if(i==0){
               a[0]=0;a[1]=0;//0は羊さん
             if(check(a))ok=1;
                }
              if(i==1){
               a[0]=0;a[1]=1;//0は羊さん
             if(check(a))ok=1;
                }  
               if(i==2){
               a[0]=1;a[1]=0;//0は羊さん
             if(check(a))ok=1;
                } 
               if(i==3){
               a[0]=1;a[1]=1;//0は羊さん
             if(check(a))ok=1;
              } 
                if(ok){
                 rep(i,0,n){
                  if(a[i]==0)cout<<'S';
                   else cout<<'W';
                 }
                  break;
                }
           }
                if(ok)
                cout<<endl;
                else{
                 cout<<-1<<endl; 
                }
}
#include <bits/stdc++.h>
using namespace std; 
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define ALL(a) (a).begin(),(a).end()
#define ll long long
long long min(long long x,long long y){return (x<y ? x:y);}
long long max(long long x,long long y){return (x>y ? x:y);}
#define ld long double
int stoi(string s) {return atoi(s.c_str());}
int keta(ll x){ if(x<10){return 1;} else{return keta(x/10) + 1;}}
#define LINEY "YES\n"
#define Liney "Yes\n"
#define LINEN "NO\n"
#define Linen "No\n"

int N;
ll func(ll a[],bool grt){
  int pl = 0;
  int pr = N-1;
  ll r=0;
  if(grt){sort(a,a+N,greater<ll>());}
  else{sort(a,a+N);}
  bool turn_l = true;
  while(pl<=pr){
    if(turn_l){
      //printf("%Ld ",a[pl]);
      r += a[pl]*2*pow(-1,grt+1);
      pl++;
    }else{
      //printf("%Ld ",a[pr]);
      r -= a[pr]*2*pow(-1,grt+1);
      pr--;
    }
    turn_l = !turn_l;
  }
  //printf("\n%Ld\n",r);
  if(N%2==1){
    if(grt){
      r -= (a[pl-1]+a[pl-2]);
    }else{
	  r += (a[pl-1]+a[pl-2]);
    }
  }else{
    if(grt){
      r -= a[pl-1];
      r += a[pr+1];
    }else{
	  r += a[pl-1];
      r -= a[pr+1];
    } 
  }
  return r;
}

int main(){
  cin >>N;
  ll a[N]; REP(i,N){cin>>a[i];}
  ll r = max(func(a,true),func(a,false));
  cout << r << "\n";
}
#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define all(v) v.begin(), v.end()
using in = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const double PI=3.14159265358979323846;
const int64_t waru = 1000000007;
const in INF=1<<30;
#define vec2(a,y,x) vector<vector<int>> a(y,vector<int>(x))
#define vec1(a,n) vector<in> a(n);rep(i,n)cin>>a[i]
vector<char> ci={'0','1','2','3','4','5','6','7','8','9'};

int cii(char x){
rep(i,10) if(ci[i]==x) return i;
}

int nC2(int n){
  int ret=n*(n-1)/2;
  return ret;
}

int cnt1(int x,string n){
 int ret= 9*(x-1)+cii(n.at(0));
  return ret;
}

int cnt2(int x,string n){
  int ret=(x-2)*(x-1)/2*81+9*(cii(n[0])-1)*(x-1);
  if(x==1) return ret;
  while(n.size()>=1){
    n =n.substr(1);
    x=n.size();
    if(n[0]!='0') break;
  }
  if(x==0) return ret;
  ret += cnt1(x,n);
  return ret;
}

int cnt3(int x,string n){
   int ret= 0;
  for(int i=2;i<=x-2;i++){
     ret += 9*9*9*nC2(i);
  }
  ret += (cii(n[0])-1)*nC2(x-1)*81;
  while(n.size()>=1){
    n =n.substr(1);
    x=n.size();
    if(n[0]!='0') break;
  }
  if(x<=2) return ret;
  ret += cnt2(x,n);
  return ret;
}


int main(){
string n;
  int k;
  cin>>n>>k;
int x =n.size();
  
if(k==1)
 cout<<cnt1(x,n)<<endl;
  
if(k==2)
   cout<<cnt2(x,n)<<endl;
  
if(k==3)
 cout<<cnt3(x,n)<<endl;
  
}

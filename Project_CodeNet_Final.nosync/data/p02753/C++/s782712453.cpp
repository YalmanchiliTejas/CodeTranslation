/*
 
Vijay Krishan Pandey
Final Year, MNNIT Allahabad
#onelasttime
 
*/
 
 
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
 
using namespace std;
 
const int MAX_N = int(1e6) + 10;
const long long int MOD=1e9+7;
const long long int INF=1e18;
 
 
typedef long long int ll;
typedef unsigned long long int llu;
 
 
 
 
 
/*
struct z_function{
  string &txt;
  int *z;
  z_function(string &_txt):txt(_txt){
    z=new int[1+txt.length()];
  }
  void cal(){
    z[0]=0;
    int l=0;
    int r=0;
    for(int i=1;i<txt.length();i++){
    //  cout<<l<<" "<<r<<endl;
      if(i>r){
        l=i;
        r=i;
        while(r<txt.length() && txt[r]==txt[r-l]){
          r++;
        }
      //  cout<<r<<" ";
        z[i]=r-l;
        r=r-1;
      }else{
              if(z[i-l]<r-i+1)
                z[i]=z[i-l];
              else{
                l=i;
                while(r<txt.length() && txt[r]==txt[r-l]){
                  r++;
                }
                z[i]=r-l;
                r=r-1;
              }
      }
    }
  }
};
*/
inline ll mul(ll a,ll b){
  a=(a+MOD)%MOD;
  b=(b+MOD)%MOD;
  ll c=a*b;
  c=(c+MOD)%MOD;
  return c;
}
inline ll add(ll a,ll b){
  a=(a+MOD)%MOD;
  b=(b+MOD)%MOD;
  ll ans=(a+b);
  ans=(ans+MOD)%MOD;
  return ans;
}
ll power(ll a,ll b,ll c){
  ll ans=1;
  while(b){
    if(b&1){
      ans=mul(ans,a);
    }
    a=mul(a,a);
    b=b/2;
  }
  return ans;
}
template<class T1, class T2>
istream &operator>>(istream &in, pair<T1, T2> &P){
  in >> P.first >> P.second;
  return in;
}
 
template<class T1, class T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &P){
  out << "(" << P.first << ", " << P.second << ")";
  return out;
}
template<class T>
istream &operator>>(istream &in, vector<T> &arr){
  for(auto &x: arr) in >> x;
  return in;
}
template<class T>
ostream &operator<<(ostream &out, const vector<T> &arr){
  for(auto &x: arr) out << x << ' '; cout << "\n";
  return out;
}
template<class T>
istream &operator>>(istream &in, deque<T> &arr){
  for(auto &x: arr) in >> x;
  return in;
}
template<class T>
ostream &operator<<(ostream &out, const deque<T> &arr){
  for(auto &x: arr) out << x << ' '; cout << "\n";
  return out;
}
mt19937 rnd(time(0));
 
inline ll gcd(ll a,ll b){
  while(b)a%=b,swap(a,b);
  return a;
}
 
 
struct SOS{
  ll *dp;
  int limit;
  vector<int>&arr;
 
  SOS(int _limit,vector<int>&v):arr(v){
 
    limit=_limit;
    dp=new ll[(1<<limit)+10];
  }
 
  void init(){
    for(int i=0;i<(1<<limit);i++){
      dp[i]=0;
    }
    for(int i=0;i<arr.size();i++){
       dp[arr[i]]++;
    }
  }
 
  void build1(){
    for(int i=0;i<limit;i++){
      for(int j=0;j<(1<<limit);j++){
        if(j&(1<<i)){
          dp[j]=add(dp[j],dp[j^(1<<i)]);
      }
    }
  }
 }
  void build2(){
    for(int i=0;i<limit;i++){
      for(int j=(1<<limit)-1;j>=0;j--){
        if(j&(1<<i)){
          dp[j^(1<<i)]=add(dp[j^(1<<i)],dp[j]);
        }
      }
    }
  }
// }
 
};
 
// string s;
int find(int arr[],int x)
{
    while(x!=arr[x])
    {
        x=arr[x];
    }
 
    return x;
}
 
void connect(int x,int arr[],int size[],int comp[],int y)
{
    int rootA=find(arr,x);
    int rootB=find(arr,y);
    if(rootA==rootB)return;
 
    if(size[rootA]<size[rootB])
    {
        arr[rootA]=rootB;
        size[rootB]+=size[rootA];
        comp[rootB]=min(comp[rootA],comp[rootB]);
    }else{
        arr[rootB]=rootA;
        size[rootA]+=size[rootB];
        comp[rootA]=min(comp[rootA],comp[rootB]);
    }
 
 
}
const int N=2e5+5;
int tree[26][500005];
void update(int x,int j,int v){
  while(x<500005){
    tree[j][x]+=v;
    x+=x&(-x);
  }
}
int query(int x,int j){
  int ans=0;
  while(x){
    ans+=tree[j][x];
    x-=x&(-x);
  }
  return ans;
}
 
void combine(int x,int y,int arr[],int size[])
{
    int rootA=find(arr,x);
    int rootB=find(arr,y);
    if(rootA==rootB)return;
 
    if(size[rootA]<size[rootB])
    {
        arr[rootA]=rootB;
        size[rootB]+=size[rootA];
    }else{
        arr[rootB]=rootA;
        size[rootA]+=size[rootB];
    }
 
 
}

ll prefix1[400005];
ll prefix2[400005];
vector<int>has1;
vector<int>has2;

int bound(vector<int> &v,int x){
  int low=0;
  int high=(int)v.size()-1;
  int ans=v.size();
//  cout<<x<<endl;
  while(low<=high){
    int mid=(low+high)/2;
    if(v[mid]>=x){
      ans=mid;
      high=mid-1;
    }else{
      low=mid+1;
    }
  }

  return ans;
}
stack<int>s1;
stack<int>s2;
int ans;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);



  string s;
  cin>>s;

  int n=s.length();
  bool f=false;
  for(int i=0;i<n-1;i++){
    if(s[i]!=s[i+1])f=true;
  }

  if(f)cout<<"Yes\n";
  else cout<<"No\n";




  
}
 
  
   
 
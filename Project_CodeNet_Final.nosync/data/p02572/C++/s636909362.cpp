#include<bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
using in = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define Yes cout<<"Yes"<<endl 
#define No cout<<"No"<<endl
#define yes cout<<"yes"<<endl 
#define no cout<<"no"<<endl
#define vec(a,y,x)  vector<vector<char>> a (y,vector<char>(x))
const double PI=3.14159265358979323846;
const in MOD = 1000000007;
const in INF=1e18+7;
const int inf=1e9+7;
const vector<int> dx={1,0,-1,0};
const vector<int> dy={0,1,0,-1};

int main(){
  int n;
  cin>>n;
  vector<in> a(n);
  rep(i,n)
    cin>>a.at(i);
  in sum=0;
  rep(i,n){
    sum+=a.at(i);
    sum=sum % MOD;
  }
  in sum2;
  sum2=sum*sum;
  
  sum2 = sum2 % MOD;
  in nijouwa=0;
  rep(i,n){
    in h=0;
    h=a.at(i)*a.at(i);
    h=h % MOD;
    nijouwa += h;
    nijouwa = nijouwa % MOD;
  }
  sum2 = sum2 + MOD - nijouwa;
  sum2 = sum2 % MOD;
  //cout<<sum2<<endl;
  if(sum2 % 2==0)
    cout<<sum2/2<<endl;
  else
    cout<<(sum2+MOD)/2<<endl;
  //cout<<nijouwa;
}
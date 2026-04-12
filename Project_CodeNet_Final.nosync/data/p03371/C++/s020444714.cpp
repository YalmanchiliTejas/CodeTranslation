#include<bits/stdc++.h>
#include<bits/stdc++.h>
#include<iomanip>
using namespace std;
typedef long long ll;
typedef long  l;
typedef pair<int,int> P;
#define rep(i,n) for(int i=0;i<n;i++)
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
const int INF=1000000001;
const double PI=3.141592653589;


int main(){
  int a,b,c,x,y; cin>>a>>b>>c>>x>>y;
  int sum=0;
  if(c*2>a+b){
    sum=a*x+b*y;
  }else{
    if(x>y){
      sum+=y*c*2;
      if((x-y)*a<(x-y)*c*2){
        sum+=(x-y)*a;
      }else{
        sum+=(x-y)*c*2;
      }
    }else{
      sum+=x*c*2;
      if((y-x)*b<(y-x)*c*2){
        sum+=(y-x)*b;
      }else{
        sum+=(y-x)*c*2;
      }
    }
  }
  cout<<sum<<endl;


  return 0;

}

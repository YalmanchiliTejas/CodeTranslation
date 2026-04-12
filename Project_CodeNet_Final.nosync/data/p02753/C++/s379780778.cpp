//inlclude前用define 
#define _USE_MATH_DEFINES

//include
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<type_traits>
#include<numeric>
//#include<deque>
#include<iomanip>
#include<set>
#include<tuple>
#include<map>
#include<limits>

using namespace std;

//typedef
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<char> VC;
typedef long long int ll;

//define
#define INF 1e9 
#define NUM 1000000007
#define all(x) begin(x), end(x)
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main(){
  string s;
  cin>>s;
  
  int cnta=0,cntb=0;
  rep(i,3){
    if(s[i]=='A') cnta++;
    else cntb++; 
  }
  
  if(cnta!=0 && cntb!=0) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}

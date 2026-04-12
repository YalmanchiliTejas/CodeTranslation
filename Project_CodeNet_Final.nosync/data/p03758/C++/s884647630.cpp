#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<math.h>
#include<string>
#include<string.h>
#include<stack>
#include<queue>
#include<vector>
#include<utility>
#include<set>
#include<map>
#include<stdlib.h>
#include<iomanip>

using namespace std;

#define ll long long
#define ld long double
#define EPS 0.0000000001
#define INF 1e9
#define MOD 1000000007
#define rep(i,n) for(i=0;i<n;i++)
#define loop(i,a,n) for(i=a;i<n;i++)
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)

typedef vector<int> vi;
typedef pair<int,int> pii;

int main(void) {
  int i,j,k;
  int n;
  cin>>n;
  queue<pii> q;
  rep(i,n-1)
    for(j=i+1;j<n;j++){
      string s="";
      rep(k,n)
        if(k!=i && k!=j)s+="0";
        else s+="1";
      cout<<"? "<<s<<endl;
      int d;
      cin>>d;
      if(d)q.push(pii(i,j));
    }

  cout<<"!";
  while(q.size()){
    cout<<" ("<<q.front().first<<","<<q.front().second<<")";
    q.pop();
  }
  cout<<endl;
}

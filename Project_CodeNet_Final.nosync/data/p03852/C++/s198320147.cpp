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
#define INF 10000000000LL
#define rep(i,n) for(i=0;i<n;i++)
#define roop(i,a,n) for(i=a;i<n;i++)
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)

typedef vector<int> vi;
typedef pair<int,int> pii;
int i,j;

int main(void) {

  string s;
  cin>>s;
  if(s[0]=='a' || s[0]=='i' || s[0]=='u' || s[0]=='e' \
|| s[0]=='o')cout<<"vowel"<<endl;
  else cout<<"consonant"<<endl;


  return 0;
}

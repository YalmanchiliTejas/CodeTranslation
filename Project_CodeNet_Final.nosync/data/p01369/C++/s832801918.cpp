#include<iostream>
#include<string.h>
#include<string>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<cmath>
#include<utility>
#include<set>
#define ll long long int
#define ld long double
#define INF 1000000000
#define EPS 0.0000000001
#define rep(i,n) for(i=0;i<n;i++)
using namespace std;
typedef pair<int, int> pii;

int main()
{
  string str;
  int hand[26]={0,0,0,0,0,0,0,
		1,1,1,1,1,1,1,1,1,
		0,0,0,0,
		1,0,0,0,1,0};
  int i;

  while(true){
    cin>>str;
    if(str[0]=='#')break;
    int ans=0;
    rep(i,str.size()-1)
      if(hand[str[i]-'a']!=hand[str[i+1]-'a'])ans++;
    cout<<ans<<endl;
  }
}
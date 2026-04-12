#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
typedef pair<ll,ll> pll;

#define reps(i,f,n) for(int i = int(f); i <= int(n); i++)
#define rep(i,n) reps(i,0,int(n)-1)
#define rrep(i,n) for(int i = n-1; i >= 0; i--)

#define all(x) (x).begin(),(x).end()
#define X first
#define Y second

#define sz size()
#define eb emplace_back

int a[26] = {1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1,1,1,0,1};

int main(void){
  string str;
  while(cin >> str){
    if(str.sz == 1 && str[0]=='#')break;
    int ans = 0;
    int status = a[str[0]-'a'];
    reps(i,1,str.sz-1){
      if(a[str[i]-'a'] != status){
        ans++;
        status = a[str[i]-'a'];
      }
    }
    cout << ans << endl;
  }
  return 0;
}
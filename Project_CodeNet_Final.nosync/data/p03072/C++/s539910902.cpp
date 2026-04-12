#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000005LL
#define MOD 1000000007

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int main(){
  int n;
  cin >> n;
  int b=0;
  int c=0;
  rep(i,0,n){
    int a;
    cin >> a;
    if(b<=a)c++;
    b = max(a,b);
  }
  cout << c << endl;

  return 0;
}

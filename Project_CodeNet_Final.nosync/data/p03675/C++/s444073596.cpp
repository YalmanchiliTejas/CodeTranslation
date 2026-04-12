#include <bits/stdc++.h>
#define pb push_back
#define mem(a, b) memset(a, b, sizeof(a))
using namespace std;
typedef long long ll;
typedef vector<int> vi;
const int MAXN = (1<<30);
const int maxn = 200000 + 50;
const int mod = 1e9+7;
int a[maxn], n;
int main(){
//freopen("input.txt", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);
  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
  }
  if(n&1){
    for(int i = n; i >= 1; i-=2)
      cout << a[i] << " ";
    for(int i = 2; i <= n-1; i+=2)
      cout << a[i] << " ";
  }
  else{
     for(int i = n; i >= 2; i-=2)
      cout << a[i] << " ";
    for(int i = 1; i <= n-1; i+=2)
      cout << a[i] << " ";
  }
  return 0; 
}
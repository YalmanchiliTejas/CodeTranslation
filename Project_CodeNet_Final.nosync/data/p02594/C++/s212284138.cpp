#include <bits/stdc++.h>
using namespace std;
#define PI 3.1415926535
const long long int MOD = 1e9+7;
#define pb push_back
#define mp make_pair
#define fill(a)  memset(a, 0, sizeof (a))
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
#define watch(x) cout << (#x) << " is " << (x) << endl;
const long long int MAXX = 2e5+5;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector< iii > viii;

ll lcm(ll a, ll b) {
   return a / __gcd(a, b) * b;
}
int XOR(int x, int y){
  return (x | y) & (~x | ~y);
}
bool cmp(const pair<int,int> &a,const pair<int,int> &b) {
    return (a.second < b.second);
}
// bool isl = binary_search(x.begin(), x.end(), 5);
// __builtin_popcount(x)  - Returns the number of set bits in x
const long long int N = 1e6;
int binsearch(int lo, int hi){
    while(lo<hi){
        int mid=(lo+hi)/2;
        if((mid))   // check(mid)
            hi=mid;
        else
            lo=mid+1;
    }
    return lo;
}
int power(int x,int y){
    int res=1;
    while(y>0){
      if(y&1) res=((res*x));

      y/=2;
      x=((x*x));
    }
    return res;
}

int main(){
    FAST
    int x;
    cin>>x;
    if(x>=30) cout<<"Yes";
    else cout<<"No";
    return 0;
}

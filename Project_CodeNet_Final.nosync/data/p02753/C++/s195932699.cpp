#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef long int li;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<float, float> ff;
typedef pair<double, double> dd;
typedef unsigned int ui;
typedef vector<ii> vii;
typedef vector<ff> vff;
typedef set<int> si;
typedef set<lli> slli;
typedef vector<lli> vlli;
typedef long long ll;
typedef long long ll;
typedef vector<ll> vll;
typedef unsigned long long int ulli;
#define MOD 1000000007
#define INF (unsigned)(~0)>>1
typedef pair<int, ii> iii;
void arr_int(int* given_arr, int n){
  for(int i=0;i<n;i++)
    scanf("%d", &given_arr[i]);
}
void solve();
int main(int argc, char const *argv[]){
  solve();
  return 0;
}
void solve(){
  string s;
  cin>>s;
  if(s[0] == s[1] && s[1] == s[2])
    printf("%s\n", "No");
  else
    printf("%s\n", "Yes");
}

#include <bits/stdc++.h>
using namespace std;
#define REP(i, x, n) for(int i = x; i < (int)(n); i++)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define F first
#define S second
#define mp make_pair
#define vecin1(n) vector<int> vec1(n); rep(i,n) cin >> vec1.at(i)
#define vecin2(n) vector<int> vec2(n); rep(i,n) cin >> vec2.at(i)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;


int main() {

int ans,n,H,y;
ans = y = 0; //y=左側にある山の最大値
cin >> n;
rep(i,n)
{
cin >> H; 
if (y<=H) //Hの山が海をみえるならば
ans++;
y=max(y,H); //今までの山の高さの最大値
}

  cout << ans << endl;
}
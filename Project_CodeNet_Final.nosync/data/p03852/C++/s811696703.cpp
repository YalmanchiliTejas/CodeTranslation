#include <bits/stdc++.h>
#define SORT(x) sort((x).begin(),(x).end())
#define ALL(x) x.begin(),x.end()
#define db(x) cout<<#x<<"="<<x<<endl
#define rep(i, n) for(int i = 0; i < n; i++)
#define reps(i, m, n) for(int i = m; i < n; i++)
#define repr(i, m, n) for(int i = m; i >= n; i--)
#define INF (1e9)
#define PI (acos(-1))
#define MOD 1000000007
using namespace std;
typedef long long ll;



void Main(){

  char c;
  cin>>c;

  cout << (c=='a' or c=='e' or c=='i' or c=='o' or c=='u'? "vowel" : "consonant") <<"\n";
}

//-----------------------------------
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  Main();
}
//-----------------------------------

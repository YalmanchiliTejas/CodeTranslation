#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)//iをaからn
#define per(i,a,n) for (int i=a-1;i>=n;i--)//iをnからa
#define db(x) cout << #x << " = " << x << endl
#define db2(x, y) cout << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n"; //デバッグ用
#define all(x) (x).begin(), (x).end()
#define INF 1000000000000 //10^12:∞
#define MOD 1000000007 //10^9+7:合同式の法

int main() {
  int N;
  cin >> N;
  
  vector<long long int> a(N);
  long long int all=0;
  rep(i,0,N){
      cin >> a.at(i);
      all+=a.at(i);
      all%=MOD;
  }
  
  //sort(all(a));
  
  long long int ans=0;
  
rep(i,0,N){
        all-=a.at(i);
        all=(all+MOD)%MOD;
        ans+=(a.at(i)*all)%MOD;
        ans%=MOD;
    }

 cout<<ans<<endl;
 
 return 0;
}
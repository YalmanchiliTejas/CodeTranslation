#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define repr(i,x,n) for(int i=x; i<(n); i++)
#define ALL(x) (x).begin(),(x).end()
#define INF 1e9
typedef long long ll;
using VI = vector<int>;
using VB = vector<bool>;
using VS = vector<string>;
using graph = vector<vector<int>>;

int main()
{
    mp::cpp_int ans=0;
    ll n;
    
    mp::cpp_int souwa=0;
cin>>n;
vector<mp::cpp_int> a(n);
for (int i = 0; i < n; i++)
{
    cin>>a.at(i);
    souwa+=a.at(i);
}
for (int i = 0; i < n; i++)
{
    ans+=a.at(i)*souwa;
    ans-=a.at(i)*a.at(i);
}
ans/=2;
ans=ans%1000000007;
cout<<ans<<endl;





    return 0;
}
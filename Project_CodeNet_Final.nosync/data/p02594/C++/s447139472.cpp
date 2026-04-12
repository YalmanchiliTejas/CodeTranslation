/* Aditya0412 */
#include <bits/stdc++.h>
using namespace std; 
typedef long long int ll;
#define pb push_back 
#define ve vector
#define vii vector < int >
#define vll vector < ll > 
#define pii pair < int , int >
#define pll pair < ll , ll >
#define vpl vector < pll >
#define fi first
#define all(a)      (a).begin(),(a).end()
#define si(x)       (int)((x).size())
#define debug(x)    cout<<#x<<" is "<<(x)<<endl;cout.flush();  
#define se second 
#define endl        '\n'
#define f(i,a,b)    for(int i=a;i<b;i++)
#define mem(a,x)          memset(a,x,sizeof(a))

// const ll mod=998244353;
const ll mod = 1000000000+7;
const ll N=1000000+6;
#define M_PI           3.14159265358979323846



// === Debug macro starts here ===

int recur_depth = 0;
#ifdef DEBUG
#define dbg(x) {++recur_depth; auto x_=x; --recur_depth; cerr<<string(recur_depth, '\t')<<"\e[91m"<<__func__<<":"<<__LINE__<<"\t"<<#x<<" = "<<x_<<"\e[39m"<<endl;}
#else
#define dbg(x)
#endif
template<typename Ostream, typename Cont>
typename enable_if<is_same<Ostream,ostream>::value, Ostream&>::type operator<<(Ostream& os,  const Cont& v){
    os<<"[";
    for(auto& x:v){os<<x<<", ";}
    return os<<"]";
}
template<typename Ostream, typename ...Ts>
Ostream& operator<<(Ostream& os,  const pair<Ts...>& p){
    return os<<"{"<<p.first<<", "<<p.second<<"}";
}

// === Debug macro ends here ===


void inp(ll *arr,ll n)
{
  for(int i=0;i<n;i++)
    cin>>arr[i];
}
void inp_mat(ll *arr,ll n,ll m)
{
    for(int i=0;i<n;i++)
      for(int j=0;j<m;j++)
        {
          ll x;cin>>x;
          *((arr+i*m) + j)=x;
        }
}
// syntax for inp_mat inp_mat((ll *)arr,n,m);
// int x2[]={+1,-1,+0,+0};
// int y2[]={+0,+0,+1,-1};
// int x2[]={+0,+0,+1,-1,-1,+1,-1,+1};
// int y2[]={-1,+1,+0,+0,+1,+1,-1,-1};
// int x2[]={-2,-2,-1,-1,+1,+1,+2,+2};
// int y2[]={-1,+1,-2,+2,-2,+2,-1,+1};
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //  #ifndef ONLINE_JUDGEc
    //   freopen ("INPUT.txt" , "r" , stdin);
    //   freopen ("OUTPUT.txt", "w" , stdout);
    // #endif 
    int t=1;
    // cin>>t;
    while(t--)
    {
      ll x;cin>>x;
      if(x>=30)
      cout<<"Yes\n";
      else
      {
        cout<<"No";
      }
      
    }    
} 
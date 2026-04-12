/*
ID: computerbox --> Huseyn Hajiyev
LANG: C++
TASK: target_mode_on
*/
#include <bits/stdc++.h>
//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#define _CRT_SECURE_NO_WARNINGS
//#include <boost/multiprecision/cpp_int.hpp>
//using boost::multiprecision::cpp_int;
#define FAST_READ ios_base::sync_with_stdio(0);
#define in freopen("input.txt", "r", stdin);
#define out freopen("output.txt", "w", stdout);
#define ll long long
#define debt(x,y)cout<<"#x = "<<(x)<<" and "<<"#y = "<<(y)<<endl;
#define deb(x)cout<<"#x = "<<(x)<<endl;
#define COUT(n, a) cout<< fixed << setprecision(a) << n<<endl
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define arr(a,n) for(ll i=1;i<=n;i++) cout<<a[i]<<" "; cout << "\n";
#define vecc(a,n) for(ll i=0;i<n;i++) cout<<a[i]<<" "; cout << "\n";
#define CURTIME() cerr << clock() * 1.0 / CLOCKS_PER_SEC << endl
#define DTIME(ccc) __begin = clock(); ccc; cerr<<"Time of work = "<<(clock()-__begin)/CLOCKS_PER_SEC<<endl;
#define MAXN 3010
//cin.ignore (7777, '\n');

using namespace std;

#define debug(args...)(Debugger()) , args
class Debugger
{
  public:
  Debugger(const std::string& _separator=", ") :
  first(true),separator(_separator){}
  template<typename ObjectType>
  Debugger& operator,(const ObjectType& v)
  {
        if(!first)cerr<<separator;
        cerr<<v;
        first=false;
        return *this;
  }
  ~Debugger() {cerr<<endl;}      
  private:
    bool first;
    string separator;
};
 
template <typename T1, typename T2>
inline ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& p)
{
   return os<<"("<<p.first<<", "<<p.second<<")";
}
template<typename T>
inline ostream &operator<<(ostream & os,const vector<T>& v)
{
    bool first=true;
    os<<"[";
    for(unsigned ll i=0;i<v.size();i++)
    {
        if(!first)os<<", ";
        os<<v[i];
        first=false;
    }
        return os<<"]";
}
template<typename T>
inline ostream &operator<<(ostream & os,const set<T>&v)
{
    bool first=true;
    os<<"[";
    for(typename set<T>::const_iterator ii=v.begin();ii!=v.end();++ii)
    {
        if(!first)os<<", ";
        os<<*ii;
        first=false;
    }
    return os<<"]";
}
template<typename T1, typename T2>
inline ostream &operator<<(ostream & os,const map<T1, T2>&v)
{
        bool first=true;
        os<<"[";
        for(typename map<T1,T2>::const_iterator ii=v.begin(); ii!=v.end();++ii)
        {
            if(!first)os<<", ";
            os<<*ii;
            first=false;
        }
        return os<<"]";
}

ll n;
ll massiv[MAXN];
ll used[MAXN][MAXN];
ll usedd[MAXN][MAXN];
ll f(ll l,ll r)
{
  if(l>r)return 0;
  if(used[l+2][r]==-1)
  {
	used[l+2][r]=f(l+2,r);
  }
  if(used[l][r-2]==-1)
  {
	used[l][r-2]=f(l,r-2);
  }
  if(used[l+1][r-1]==-1)
  {
	used[l+1][r-1]=f(l+1,r-1);
  }
  ll one=massiv[l]+min(used[l+2][r],used[l+1][r-1]);
  ll two=massiv[r]+min(used[l][r-2],used[l+1][r-1]);
  return max(one,two);
}




int main(){
FAST_READ;
cin>>n;
ll sum=0;
for(ll i=1;i<=n;i++)
{
  cin>>massiv[i];
  sum+=massiv[i];
}
memset(used,-1,sizeof(used));
ll one=f(1,n);
ll two=sum-one;

cout<<one-two<<endl;
return 0;
} 

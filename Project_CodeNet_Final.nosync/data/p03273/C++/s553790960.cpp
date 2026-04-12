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
#define FAST_READ ios_base::sync_with_stdio(0);cin.tie(0);
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
#define MAXN 2000

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

ll used[MAXN][MAXN];
char massiv[MAXN][MAXN];
char mm[MAXN][MAXN];
char mmm[MAXN][MAXN];
ll n,m;
int main(){
FAST_READ;
cin>>n>>m;
for(ll i=1;i<=n;i++)
{
  for(ll j=1;j<=m;j++)
  {
    cin>>massiv[i][j];
  }
}
for(ll i=1;i<=n;i++)
{
  ll sig=1;
  for(ll j=1;j<=m;j++)
  {
    if(massiv[i][j]=='#'){sig=0;break;}
    else used[i][j]=2;
  }
  if(sig==0)
  {
    for(ll j=1;j<=m;j++)
    {
      used[i][j]=0;
    }
  }
}

for(ll i=1;i<=m;i++)
{
  ll sig=1;
  for(ll j=1;j<=n;j++)
  {
    if(massiv[j][i]=='#'){sig=0;break;}
    else if(used[j][i]!=2)used[j][i]=1;
  }
  if(sig==0)
  {
    for(ll j=1;j<=n;j++)
    {
      if(used[j][i]!=2)used[j][i]=0;
    }
  }
}


ll ds=0;
ll ini=1,iny=1;
ll prev=1;
for(ll i=1;i<=n;i++)
{
  ll posl=-1;
  for(ll j=1;j<m;j++)
  {
    if(used[i][j]==0)
    {
      //if(ini!=i)ini++,iny=1,prev=i;
      ds=max(ds,iny);
      posl=1;
      mm[ini][iny]=massiv[i][j];
      iny++;
    }
  }
  if(used[i][m]==0)
  {
    posl=1;
    ds=max(ds,iny);
     mm[ini][iny]=massiv[i][m];
  }
  if(posl!=-1)
  {
    iny=1;
    ini++;
  }
}
for(ll i=1;i<=n;i++)
{
  for(ll j=1;j<=m;j++)
  {
    if((ll)mm[i][j]!=0)cout<<mm[i][j];
  }
  if((ll)mm[i][1]!=0)cout<<endl;
}





return 0;
} 

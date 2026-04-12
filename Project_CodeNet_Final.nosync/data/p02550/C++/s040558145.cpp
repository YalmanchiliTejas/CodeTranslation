#include <bits/stdc++.h>
#define int long long int
#define ll long long int
#define ld long double
#define getFaster ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define rep(i, init, n) for (int i = init; i < (int)n; i++)
#define rev(i, n, init) for (int i = (int)n; i >= init; i--)
#define MOD1 1e9 + 7
#define MOD2 998244353
#define f first
#define s second
#define endl '\n'
#define pii pair<int, int>
#define piii pair<pii, int>
#define precise(i) cout << fixed << setprecision(i)
#define codejam cout << "Case #" << ii + 1 << ": ";
#define impossible cout << "IMPOSSIBLE" << endl;
#define error(s) throw runtime_error(s)
std::mt19937_64 rng(std::chrono::steady_clock::now().time_since_epoch().count());
int myRand(int R){int val=rng()%R;assert(val >= 0);return val;}

const long double PI = atan(1.0) * 4;
const int64_t INF64 = 3e18;
const int32_t INF32 = 2e9 + 7;
const int32_t LOG = 21;
const int32_t MOD = MOD1;

using namespace std;


//-------------------DEBUGGING-------------------------
void my_debugger(string s,int LINE_NUM){cerr<<endl;}
template<typename start,typename... end>
void my_debugger(string s,int LINE_NUM,start x,end... y) 
{
    if(s.back()!=',') {s+=',';cerr<<"LINE("<<LINE_NUM<<"): ";}
    int i=s.find(',');
    cerr<<s.substr(0,i)<<" = "<<x;
    s=s.substr(i+1);
    if(!s.empty()) cerr<<", ";
    my_debugger(s,LINE_NUM,y...);
}

#ifdef AJIT
#define debug(...) my_debugger(#__VA_ARGS__,__LINE__,__VA_ARGS__);
#else
#define debug(...) ;
#endif

//-----------------------------------------------------



int32_t main()
{
      getFaster;
      //files_init();
      int tests = 1;
      //cin >> tests;
      rep(ii, 0, tests)
      {
           int n,x,m;
           cin>>n>>x>>m;
           vector<int> seq;
           vector<bool> check(m,false);
           vector<int> ind(m,0);

           int cur=x;
           int it=0;
           
           while(!check[cur])
           {
                check[cur]=true;
                ind[cur]=it;
                seq.push_back(cur);
                cur=(cur*cur)%m;
                it++;
           }


           bool start=false;
           int ind1=-1;
           int len=0;
           int sum_loop=0;

           rep(i,0,seq.size())
           {
                 if(seq[i]==cur){start=true;ind1=i;}
                 if(start){sum_loop+=seq[i];len++;}  
           }


           int siz=seq.size();

           if(n<=siz)
           {
               int ans=0;
               rep(i,0,n)ans+=seq[i];
               cout<<ans<<endl;
               return 0;
           }


           int ans=0;
           rep(i,0,seq.size())ans+=seq[i];

           n-=siz;
           
           int div=n/len;
           ans+=div*sum_loop;

           int rem=n%len;
           rep(i,ind1,seq.size())
           {
               if(rem==0)break;
               rem--;
               ans+=seq[i];
           }

           cout<<ans<<endl;


           

      }
      return 0;
}

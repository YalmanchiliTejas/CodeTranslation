#include <bits/stdc++.h>
#define XOX
using namespace std;

#define fast ios_base::sync_with_stdio(false),cin.tie(NULL)
#define ldb long double 
#define db double
#define int long long

#define fr first
#define se second
#define lb lower_bound 
#define ub upper_bound 
#define pb push_back
#define mpr make_pair

#define pi pair<int,int>
#define pdb pair<db,db>
#define pldb pair<ldb,ldb>

#define vi vector<int>
#define vdb vector<db>
#define vldb vector<ldb>
#define vpi vector< pi >

#define mi map<int,int>
#define mdb map<db,db>
#define mldb map<ldb,ldb>


#define forr(a,b) for (int i = (a); i < (b); ++i)
#define rrof(a,b) for (int i = (b)-1; i >= (a); --i)

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)

const int md = 1e9+7;
const int MX = 2e5+5;
const int INF = 1e18; 
const ldb PI = 4*atan((ldb)1);

int power_md(int a,int n)
{
 int res=1;
 while(n)
{
 if(n%2)
  res=(res%md*a%md)%md;
  a=(a%md*a%md)%md;
  n/=2;
}
res%=md;
return res;
}

int power(int a,int n)
{
 int res=1;
 while(n)
{
 if(n%2)
  res*=a;
  a=a*a;
  n/=2;
}
return res;
}

int abst(int a)
{
 return ((a<0)?(-1*a):(a));
}

class cmp_set{
public:
	bool operator() (int a, int b){
		return a > b;
	}
};

vector<string> vec_splitter(string s) {
	s += ',';
	vector<string> res;
	while(!s.empty()) {
		res.push_back(s.substr(0, s.find(',')));
		s = s.substr(s.find(',') + 1);
	}
	return res;
}
void debug_out(
vector<string> __attribute__ ((unused)) args,
__attribute__ ((unused)) int idx, 
__attribute__ ((unused)) int LINE_NUM) { cerr << endl; } 
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
	if(idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";
	stringstream ss; ss << H;
	cerr << args[idx] << " = " << ss.str();
	debug_out(args, idx + 1, LINE_NUM, T...);
}
#ifdef XOX
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
#define debug(...) 42
#endif

int n,x;

int l[51],p[51];

int fun(int cn,int cx)
{
    if(cn==0)
    {
        if(cx<=0)
         return 0;
         else
          return 1;
    }
    else if(cx==1)
     return 0;
    else if(cx<=1+l[cn-1])
     return fun(cn-1,cx-1);
     else if(cx==(2+l[cn-1]))
      return p[cn-1]+1;
     else if(cx<=2+2*l[cn-1])
      return (p[cn-1]+1+fun(cn-1,cx-l[cn-1]-2));
      else
       return (2*p[cn-1]+1);
}

int32_t main()
{
    fast;
    cin>>n>>x;
    l[0]=1;
    p[0]=1;
    for(int i=1;i<51;i++)
    {
        l[i]=2*l[i-1]+3;
        p[i]=2*p[i-1]+1;
    }
    int res=fun(n,x);
    cout<<res<<"\n";
    return 0;
}
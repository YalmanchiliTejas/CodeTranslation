#include <bits/stdc++.h>
using namespace std;
#define pb 		push_back
#define mp 		make_pair
#define pii 	pair<int,int>
#define vi 		vector<int>
#define vii 	vector<vector<int>>;
#define vpii 	vector<pii>
#define ar 		array
#define SZ(x) 	((int)(x.size()))
#define fi 		first
#define se 		second


#define TRvi(a,it)   for(auto (it)=(a).begin(),it!=(a).end();it++) 	
#define FORV (a,x)   for(auto (x):(a))
#define FOR(i,n)	 for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) 	for(int (i)=1;(i)<=(n);++(i))
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)

#define IN(x,y) 	((y).find((x))!=(y).end())
#define ALL(t) 		t.begin(),t.end()

#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define DBG cerr << "debug here" << endl;
#define DBGV(vari) cerr << #vari<< " = "<< (vari) <<endl;
#define all(x) (x).begin(), (x).end()
#define str(s) to_string(s);

typedef long long ll;

const int INF = 1e9;

const int MINV = 1;
const int MAXV = 10;
#define M (ll)1000000007

    long long mod(long long x){
        return (x%M);
    }
    long long add(long long a, long long b){
        return mod(mod(a)+mod(b));
    }
    long long mul(long long a, long long b){
        return mod(mod(a)*mod(b));
    }

int32_t main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	cin>>n;
	vi A(n);
	ll pre[n];
	
	ll sum=0;
	for(int i=0;i<n;i++){
	    cin>>A[i];
	}
	pre[n-1]=A[n-1];
	for(int i=n-2;i>=0;i--){
	    
	    pre[i]=pre[i+1]+A[i];
	  
	}

	for(int i=1;i<n;i++){
	    
	    sum=add(sum,mul(A[i-1],pre[i]));
	}
	cout<<sum<<endl;
	
	
    
    
  return 0;  
}


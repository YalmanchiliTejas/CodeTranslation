#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<int>;
using vvi=vector<vi>;
using vd=vector<double>;
using vvd=vector<vd>;
using vl=vector<ll>;
using vvl=vector<vl>;
using pii=pair<int,int>;
using vs=vector<string>;
#define rep(i,n) range(i,0,n)
#define range(i,a,n) for(int i=a;i<n;i++)
#define all(a) a.begin(),a.end()
#define LINF    	((ll)1ll<60)
#define INF     	((int)1<<30)
#define EPS     	(1e-9)
#define MOD     	(1000000007)
#define fcout(a)	cout<<setprecision(a)<<fixed
#define fs 			first
#define sc			second
#define PI			3.141592653589793

template<class S,class T>ostream& operator<<(ostream&os,pair<S,T>p){os<<"["<<p.first<<", "<<p.second<<"]";return os;};
template<class S>auto&operator<<(ostream&os,vector<S>t){bool a=1; for(auto s:t){os<<(a?"":" ")<<s; a=0;} return os;}

int main(){
	cin.tie(0);
   	ios::sync_with_stdio(false);
	
	int h,w;
	cin>>h>>w;
    vvi f(h,vi(w));
    rep(i,h)rep(j,w){char c;cin>>c;f[i][j]=c=='#'?1:0;}
    set<int> x,y;
    rep(i,h){int p=0;rep(j,w)p+=f[i][j];if(p==0)y.insert(i);}
    rep(j,w){int p=0;rep(i,h)p+=f[i][j];if(p==0)x.insert(j);}
    rep(i,h){
        if(y.find(i)!=y.end())continue;
        rep(j,w){
            if(x.find(j)!=x.end())continue;
            cout<<(f[i][j]?"#":".");
        }
        cout<<endl;
    }

	return 0;
}

//raja1999

//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <string> 
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <iomanip> 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
//setbase - cout << setbase (16)a; cout << 100 << endl; Prlls 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 <<endl;prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val

using namespace std;
using namespace __gnu_pbds;
#define f(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define vi vector< int >
#define vl vector< ll >
#define ss second
#define ff first
#define ll unsigned long long int
#define pii pair< int,int >
#define pll pair< ll,ll >
#define sz(a) a.size()
#define inf (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >
//#define int ll

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;


//std::ios::sync_with_stdio(false);
ll a[505][505],ans[505][505];
ll u[505],v[505],s[505],t[505],n;
ll solve(ll b){
	ll i,j;
	rep(i,n){
		rep(j,n){
			a[i][j]=-1;
		}
	}
	vi row,col;
	rep(i,n){
		if(s[i]==0){
			if(u[i]&(1LL<<b)){
				rep(j,n){
					a[i][j]=1;
				}
			}
			else{
				row.pb(i);
			}
		}
		else{
			if(!(u[i]&(1LL<<b))){
				rep(j,n){
					a[i][j]=0;
				}
			}
			else{
				row.pb(i);
			}
		}
	}
	rep(i,n){
		if(t[i]==0){
			if(v[i]&(1LL<<b)){
				rep(j,n){
					if(a[j][i]==0){
						return 0;
					}
					a[j][i]=1;
				}
			}
			else{
				col.pb(i);
			}
		}
		else{
			if(!(v[i]&(1LL<<b))){
				rep(j,n){
					if(a[j][i]==1){
						return 0;
					}
					a[j][i]=0;
				}
			}
			else{
				col.pb(i);
			}
		}
	}
	if(row.size()==0&&col.size()==0){
		return 1;
	}
	ll one,zero,fl;
	if(row.size()==0){
		rep(j,col.size()){
			one=0;
			zero=0;
			rep(i,n){
				if(a[i][col[j]]==1){
					one++;
				}
				else{
					zero++;
				}
			}
			if(t[col[j]]==0&&zero==0){
				return 0;
			}
			if(t[col[j]]==1&&one==0){
				return 0;
			}
		}
		return 1;
	}
	if(col.size()==0){
		rep(j,row.size()){
			one=0;
			zero=0;
			rep(i,n){
				if(a[row[j]][i]==1){
					one++;
				}
				else{
					zero++;
				}
			}
			if(s[row[j]]==0&&zero==0){
				return 0;
			}
			if(s[row[j]]==1&&one==0){
				return 0;
			}
		}
		return 1;
	}
	ll val=0,val1=0,val2=0,val3=0;
	rep(i,row.size()){
		if(s[row[i]]==0){
			val++;
		}
		if(s[row[i]]==1){
			val1++;
		}
	}
	rep(i,col.size()){
		if(t[col[i]]==1){
			val3++;
		}
		else{
			val2++;
		}
	}
	if(val>0&&val2>0){
		rep(i,row.size()){
			rep(j,col.size()){
				if(s[row[i]]==0&&t[col[j]]==0){
					a[row[i]][col[j]]=0;
				}
			}
		}
		rep(i,n){
			rep(j,n){
				if(a[i][j]==-1){
					a[i][j]=1;
				}
			}
		}
		return 1;
	}
	if(val1>0&&val3>0){
		//cout<<"ho"<<endl;
		rep(i,row.size()){
			rep(j,col.size()){
				if(s[row[i]]==1&&t[col[j]]==1){
					a[row[i]][col[j]]=1;
				}
			}
		}
		rep(i,n){
			rep(j,n){
				if(a[i][j]==-1){
					a[i][j]=0;
				}
			}
		}
		return 1;
	}
	if(row.size()>=2&&col.size()>=2){
		fl=0;
		rep(i,row.size()){
			a[row[i]][col[fl]]=s[row[i]];
			fl=(fl^1);
		}
		rep(i,n){
			rep(j,n){
				if(a[i][j]==-1){
					a[i][j]=(s[row[0]]^1);
				}
			}
		}
		return 1;
	}
	if(row.size()==1){
		rep(i,col.size()){
			one=0;
			zero=0;
			rep(j,n){
				if(a[j][col[i]]==1){
					one++;
				}
				else if(a[j][col[i]]==0){
					zero++;
				}
			}
			if(t[col[i]]==0&&zero==0){
				a[row[0]][col[i]]=0;
			}
			else if(t[col[i]]==1&&one==0){
				a[row[0]][col[i]]=1;
			}
			else{
				a[row[0]][col[i]]=s[row[0]];
			}
		}
		return 1;
	}
	if(col.size()==1){
		rep(i,row.size()){
			one=0;
			zero=0;
			rep(j,n){
				if(a[row[i]][j]==1){
					one++;
				}
				else if(a[row[i]][j]==0){
					zero++;
				}
			}
			if(s[row[i]]==0&&zero==0){
				a[row[i]][col[0]]=0;
			}
			else if(s[row[i]]==1&&one==0){
				a[row[i]][col[0]]=1;
			}
			else{
				a[row[i]][col[0]]=t[col[0]];
			}
		}
		return 1;
	}
}
int main(){
	std::ios::sync_with_stdio(false); cin.tie(NULL);
	ll i,j,b,val;
	cin>>n;
	rep(i,n){
		cin>>s[i];
	}
	rep(i,n){
		cin>>t[i];
	}
	rep(i,n){
		cin>>u[i];
	}
	rep(i,n){
		cin>>v[i];
	}
	rep(b,64){
		if(solve(b)==0){
			//cout<<b<<endl;
			cout<<-1<<endl;
			return 0;
		}
		rep(i,n){
			rep(j,n){
				if(a[i][j])
					ans[i][j]+=(1LL<<b);
			}
		}
	}

	rep(i,n){
		val=ans[i][0];
		f(j,1,n){
			if(s[i]==0){
				val=(val&ans[i][j]);
			}
			else{
				val=(val|ans[i][j]);
			}
		}
		if(val!=u[i]){
			//cout<<"hi"<<endl;
			cout<<-1<<endl;
			return 0;
		}
	}
	rep(j,n){
		val=ans[0][j];
		f(i,1,n){
			if(t[j]==0){
				val=(val&ans[i][j]);
			}
			else{
				val=(val|ans[i][j]);
			}
		}
		if(val!=v[j]){
			//cout<<"hi"<<endl;
			cout<<-1<<endl;
			return 0;
		}
	}
	rep(i,n){
		rep(j,n){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
} 

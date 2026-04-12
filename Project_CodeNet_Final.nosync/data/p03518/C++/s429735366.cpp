#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vt vector
#define pb push_back
#define pob pop_back
#define vi vt<int>
#define vvi vt<vi>
#define vii vt<ii>
#define vvii vt<vii>
typedef long long ll;
#define For(i,a,b) for(int i = a; i < b; i++)
#define foR(i,a,b) for(int i = a; i <= b; i++)
#define roF(i,a,b) for(int i = a - 1; i >= b; i--)
#define Rof(i,a,b) for(int i = a; i >= b; i--)

int a[1000];
vi ans;
signed main (){
//	freopen("test.inp","r",stdin);
//	freopen(".out","w",stdout);
	int n;
	cin >> n;
	For(i,0,n){
		cin >> a[i];
	}
	Rof(i,n-1,0){
		int vt;
		For(j,0,n){
			if(a[j] == i){
				vt = j;
				break;
			}
		}
		if(vt == i){
			continue;
		}
		For(j,0,vt){
			ans.pb(1);
		}
		For(j,vt,i){
			ans.pb(1);
			ans.pb(n-1);		
		}
		For(j,i,n){
			ans.pb(1);
		}
		For(j,vt,i){
			swap(a[j],a[j+1]);
		}
	}
	cout << ans.size() << "\n";
	For(i,0,ans.size()){
		cout << ans[i] << "\n";
	}
}


#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <climits>
#include <cmath>
#include <map>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++ )
#define repf(i,m,n) for(int (i)=m;(i)<n;(i)++)
#define all(v) (v).begin(), (v).end()
#define ll long long
#define vec(name,num) vector<ll> name((num),0);
#define op(i) cout<<(i)<<endl;
#define ip(i) cin>>(i);
#define opN cout<<"No"<<endl;
#define opY cout<<"Yes"<<endl;
#define opP cout<<"Possible"<<endl;
#define opI cout<<"Impossible"<<endl;
#define mat(name,fnum,snum); vector<vector<ll>> name((fnum),vector<ll>((snum),0));
#define debugP int debug_point; cin>>debug_point;
const ll MOD= 1e9 + 7;
template <typename T>
void putv(vector<T>& V){
	// cout << "The elements in the vector are: " << endl;
	for(auto x: V)
		cout << x << " ";
	cout << endl;
}
template <class T>
vector<T> getv(ll n){
	vector<T> Vector_temp;
	rep(i,n){
		T input;
		cin >> input;
		Vector_temp.emplace_back(input);
	}
	return Vector_temp;
}
ll gcd(ll c,ll b){
    while(1){
        if(c%b!=0){
        ll tmp=b;
        b=c%b;
        c=tmp;
        }else{
            return b;
        }
    }
}
/* <3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3*/
ll ans=0;
vec(vis,9);
vector<pair<ll,ll>> a(30);
mat(gra,30,30);

void dfs(ll d,ll now,ll ma){
    if(d==ma){
        ans++;
        //cout<<endl;
        return;
    }
    for(int i=1;i<=ma;i++){
        if(gra[now][i]>0&&vis[i]==0){
            vis[i]=1;
            //op(i);
            dfs(d+1,i,ma);
            vis[i]=0;
        }
    }
    return ;
    
}

int main(){
    ll n,m;
    cin>>n>>m;
    rep(i,m){
        cin>>a[i].first>>a[i].second;
        gra[a[i].first][a[i].second]++;
        gra[a[i].second][a[i].first]++;
    }
    vis[1]=1;
    dfs(1,1,n);
    op(ans);
    return 0;
}
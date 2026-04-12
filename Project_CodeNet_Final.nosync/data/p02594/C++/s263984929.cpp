/*
<3 <3 <3 Rose <3 <3 <3

BLACKPINK!
Ah yeah, ay yeah!
BLACKPINK!b
Ah yeah, ay yeah!

[Verse 1: Jennie]
Chakan eolgure geureochi mothan taedo
Ganyeorin mommae sok garyeojin volumeeun du baero
Geochimeopsi jikjin guji bojin anchi nunchi
Black hamyeon Pink urin yeppeujanghan Savage

[Verse 2: Lisa]
Wonhal ttaen daenoko ppaetji
Neon mwol haedo kallo mul begi
Du sonen gadeukan fat check
Gunggeumhamyeon haebwa fact check
Nun nopin kkokdaegi
Mul mannan mulgogi
Jom dokae nan Toxic
You hokae I`m Foxy

[Pre-Chorus: Rosé & Jisoo]
Du beon saenggakae
Heunhan namdeulcheoreom chakan cheogeun mot hanikka
Chakgakaji ma
Swipge useojuneun geon nal wihan geoya
Ajigeun jal moreugetji
Guji wonhamyeon test me
Neon bul bodeusi ppeonhae
Manmanhan geol wonhaetdamyeon

[Chorus: Jennie]
Oh wait til’ I do what I (do)
Hit you with that ddu-du ddu-du du (Ah yeah, ay yeah!)
Hit you with that ddu-du ddu-du du (Ah yeah, ay yeah!)

[Verse 3: Jennie]
BLACKPINK
Jigeum naega georeoganeun georin
BLACKPINK 4 way sageori
Dongseonambuk sabangeuro run it
Need a bucket list ssak da I bought it
Neol danggineun geotdo meolli milchineun geotdo
Jemeotdaero haneun bad girl
Jokeon sileohageon nuga mwora hadeon
When the bass drop it’s another banger

[Pre-Chorus: Jisoo & Rosé]
Du beon saenggakae
Heunhan namdeulcheoreom chakan cheogeun mot hanikka
Chakgakaji ma
Swipge useojuneun geon nal wihan geoya
Ajigeun jal moreugetji
Guji wonhamyeon test me
Neon bul bodeusi ppeonhae
Manmanhan geol wonhaetdamyeon

[Chorus: Jennie & Lisa]
Oh wait til’ I do what I (do)
Hit you with that ddu-du ddu-du du (Ah yeah, ay yeah!)
Hit you with that ddu-du ddu-du du (Ah yeah, ay yeah!)

[Bridge: Rosé & Lisa]
What you gonna do when I
Come come through with that that uh uh huh
What you gonna do when I
Come come through with that that uh uh huh
Tteugeowo tteugeowo tteugeowo like fire
Tteugeowo tteugeowo tteugeowo like fire

[Drop: All, Jisoo & Rosé]
BLACKPINK! Hey!
Ah yeah, ay yeah! Ah yeah, ay yeah!
Tteugeowo tteugeowo tteugeowo like fire
Tteugeowo tteugeowo tteugeowo like fire

[Outro: Jennie]
Hit you with that ddu-du ddu-du du
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace __gnu_pbds;

#define fi first
#define se second
#define pb push_back
#define mkp make_pair
#define foreach(it, v) for(auto it=(v).begin(); it != (v).end(); ++it)
#define gcd(a,b) __gcd(a,b)
#define ld long double
#define pb push_back
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define int long long
#define ull unsigned long long
#define pii pair<int,int>
#define vii vector<int>
#define fi first
#define se second
#define all(container) container.begin(), container.end()
#define onlyunique(v) v.erase(unique(all(v)), v.end());
#define endl '\n'
#define print(array, n)    for(int macro_i = 0; macro_i < n; macro_i ++) {cout << array[macro_i] << " ";}cout << "\n";

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define filer() freopen("input.txt","r",stdin);
#define filew() freopen("output.txt","w",stdout);

#define tr(...) cout<<__FUNCTION__<<' '<<__LINE__<<" = ";trace(#__VA_ARGS__, __VA_ARGS__)

using namespace std;

int power(int x, int y, int mod = 2e18) { int ans = 1; x %= mod; while (y) {if (y & 1)ans = (x * ans) % mod; x = (x * x) % mod; y >>= 1;} return ans;}
int modinv(int a, int m) {return power(a, m - 2, m);}
ll modI(ll a, ll m){ll m0=m,y=0,x=1;if(m==1) return 0;while(a>1){ll q=a/m;ll t=m;m=a%m;a=t;t=y;y=x-q*y;x=t;}if(x<0) x+=m0;return x;}

template<typename S, typename T> 
ostream& operator<<(ostream& out,pair<S,T> const& p){out<<'('<<p.fi<<", "<<p.se<<')';return out;}

template<typename T>
ostream& operator<<(ostream& out,vector<T> const& v){
int l=v.size();for(int i=0;i<l-1;i++)out<<v[i]<<' ';if(l>0)out<<v[l-1];return out;}

template<typename T>
void trace(const char* name, T&& arg1){cout<<name<<" : "<<arg1<<endl;}

template<typename T, typename... Args>
void trace(const char* names, T&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cout.write(names, comma-names)<<" : "<<arg1<<" | ";trace(comma+1,args...);}

const ld PI = 3.1415926535897932384626433832795;

typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> indexed_set;  // find_by_order(x)[xth element in the set counting from zero] , 
																									//	order_of_key(x) [no of elements strictly smaller than x]

void solve(){
	
	int x;
	cin >> x;
	if(x>=30)cout << "Yes\n";
	else cout << "No\n";

}

signed main(){ 
	fastio();
	int t = 1;
	// cin >> t;

	// clock_t t1, t2;
	// t1 = clock();

	while(t--){
		solve();
	}

	// t2 = clock(); cout << "\n\ntime taken: " << (t2-t1)/(ld)CLOCKS_PER_SEC << endl;

	return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define fi first
#define se second
#define pb push_back
#define rep(i, s, n) for (int i = s; i < n; i++)
#define rrep(i, s, n) for (int i = (n)-1; i >= (s); i--)
#define REP(i,n) for(int i = 0;i < n; i++)
#define all(a) a.begin(),a.end()
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
const long long MOD = 1000000007, INF = 1e18;
 
#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0)
 
template<class T>inline bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}
template<class T>inline bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}
template<typename T>vector<T>
make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts){
	return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}
 
template<typename T,typename V>
typename enable_if<is_class<T>::value==0>::type
fill_v(T &t,const V &v){t=v;}
 
template<typename T,typename V>
typename enable_if<is_class<T>::value!=0>::type
fill_v(T &t,const V &v){
	for(auto &e:t) fill_v(e,v);
}

/*bool operator<(const data &d)const{
	return hoge;
}*/
 
const int dx[]={0,1,1,-1,-1,0};
const int dy[]={1,1,0,0,-1,-1};
set<char>vowel={'a','i','u','e','o'};

int marume(int x){
	if(x>255)return 255;
	if(x<=0)return 0;
	return x;
}

int H;
vector<vector<int>>getJfen(string s){
	int W = 0;
	H = 0;
	rep(i,0,s.size()){
		if(s[i]=='/')break;
		if(s[i]=='b')W++;
		else W+=s[i]-'0';
	}
	rep(i,0,s.size())if(s[i]=='/')H++;
	vector<vector<int>>mat(H+1,vector<int>(W,0));
	int tate = 0,yoko = 0;
	rep(i,0,s.size()){
		if(s[i]=='b')mat[tate][yoko++] = 1;
		else if(s[i]=='/'){
			yoko=0;
			tate++;
		}else{
			yoko+=s[i]-'0';
		}
	}
	return mat;
}
 
signed main(){
	IOS();
	vector<string>ans;
	while(1){
		string s;
		cin>>s;
		if(s=="#")break;
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		auto banmen = getJfen(s);
		banmen[a-1][b-1]=0;banmen[c-1][d-1]=1;
		string t="";
		int spase;
		rep(i,0,H+1){
			spase = 0;
			rep(j,0,banmen[i].size()){
				if(banmen[i][j]==1){
					if(spase)t+=spase+'0';
					t+='b';
					spase = 0;
				}else spase++;
			}
			if(spase)t+=spase+'0';
			if(i!=H)t+='/';
		}
		ans.push_back(t);
	}
	for(auto e:ans){
		cout<<e<<endl;
	}
}

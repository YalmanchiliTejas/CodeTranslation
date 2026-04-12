#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0; i<n ; ++i)
#define REP(i,a,b) for(int i=a; i<b; ++i)
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;

//プロトタイプ宣言
void faster(void);
template <class T>
T gcd(T , T);
template <class T>
T get_digent(T);
template <class T>
T POW(T , T);
template <class T>
T vec_max(auto & , string);
template <class T>
T vec_min(auto & , string);

ll n,x;
vector<long long> a(100);
vector<long long> p(100);

ll dfs(int level, ll patty){
  if (level == 0) {
		if (patty <= 0) return 0;
		return 1;
	}
	else if (patty <= 1 + a[level-1]) return dfs(level-1, patty-1);
	return p[level-1] + 1 + dfs(level-1, patty-2-a[level-1]);
}


int main(){
  faster();
  cin >> n >> x;
  for(int i=0;i<n+1;i++){
    if(i==0){
      a[i]=1;
      p[i]=1;
    }
    else{
      a[i] = a[i-1]*2+3;
      p[i] = p[i-1]*2+1;
    }
  }
  cout << dfs(n,x) << endl;
}



























//同期解除
void faster(void){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
}

//ユークリッドの互除法
template <class T>
T gcd(T a, T b) {
  return (b ? gcd(b, a%b) : a);
} 

//桁数取得
template <class T>
T get_digent(auto x){
  string s;
  s = to_string(x);
  ll digent = s.size();
  return digent;
} 

//べき乗計算
template <class T>
T POW(T x, T y){
  if(y==0) return 1;
  if(y%2 == 1){
    ll temp = POW(x,y-1);
    return (temp*x);
  }
  else{
    ll temp = POW(x,y/2);
    return temp*temp;
  }
} 

//配列内の最大要素の添え字取得or要素取得
template <class T>
T vec_max(auto &v, string s){
  auto itr = max_element(v.begin(),v.end());
  ll element = *itr;
  ll place = itr - v.begin();
  if(s == "element") return element;
  else if(s == "place") return place;
  else return -1;
}

//配列内の最小要素の添え字取得or要素取得
template <class T>
T vec_min(auto &v, string s){
  auto itr = min_element(v.begin(),v.end());
  ll element = *itr;
  ll place = itr - v.begin();
  if(s == "element") return element;
  else if(s == "place") return place;
  else return -1;
}
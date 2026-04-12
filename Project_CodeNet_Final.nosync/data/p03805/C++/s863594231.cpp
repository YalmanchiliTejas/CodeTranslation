#include<bits/stdc++.h>
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
using namespace std;

//ループマクロ
#define FOR(i , a , b)  for(int i = (a) ; i < (b) ; i++)
#define REP(i , n)      for(int i = 0 ; i < n ; i++)
#define REPR(i , n)     for(int i = n ; 0 <= i ; i--)
#define ROP(i, n)       for(int i = 1 ; i <= n ; i++)

//入出力
#define SCOUT(x) cout << (x) << " "
#define VECCIN(x) for(auto& ele : (x) ) cin >> ele
#define VECOUT(x) for(auto& ele : (x) ) cout << ele << " "; cout << endl;

//その他
#define ALL(obj) (obj).begin() , (obj).end() 
#define SORT(obj) sort(ALL(obj))
#define GSORT(obj) sort(ALL(obj) , greater<int>())
#define VLL vector<long long>
#define M map<int, int>
#define S set<int>
#define V vector<int>
#define PQ priority_queue<int>
#define PQG priority_queue<int , V , greater<int>>


int main(void) {

	ios::sync_with_stdio(false);	cin.tie(0);
	int n, m;      cin >> n >> m;
	vector<set<int>>  edge(n);
    REP(i, m){
      int a, b;  cin >> a >> b;
      edge[a-1].insert(b-1);
      edge[b-1].insert(a-1);
    }

    ll ans = 0;
    vector<int>  node(n);  REP(i, n)  node[i] = i;
    do{
      	bool flag = true;
      	for(int i = 0 ; i < n-1 ; i++)
          if(edge[node[i]].count(node[i+1]) != 1){  flag = false;  break;  }
      	
      	if(flag)  ans++;
    }while(next_permutation(node.begin(), node.end()) && node[0] == 0);

    cout << ans << endl;
  	return 0;
}

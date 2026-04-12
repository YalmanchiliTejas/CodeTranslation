//header{{{
#include<bits/stdc++.h>
  
using namespace std;
 
#define rep(i,n) for(int i=0;i<(n);++i)
#define reps(i,n) for(int i=1;i<=(n);++i)
#define all(x) (x).begin(),(x).end()
#define setout(n,x) setw(n+1) << setfill(x)
#define Fixed fixed << setprecision(10)
#define int int64_t
using pii = pair<int,int>;
constexpr int INF  = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr int mod = 1e9+7; 
constexpr int MOD = 998244353;

template <class A, class B> inline bool chmax(A &a, const B &b) { return b > a && (a = b, true); }
template <class A, class B> inline bool chmin(A &a, const B &b) { return b < a && (a = b, true); }

template <class T> using min_heap = priority_queue<T,vector<T>,greater<T> >;
template <class T> using max_heap = priority_queue<T>;
template <class A, class B> using umap = unordered_map<A,B>;
  
int gcd(int a,int b){ return b ? gcd(b,a % b) : a;}
int lcm(int a,int b){ return a / gcd(a,b) * b;}

constexpr int dx[] = {1,0,-1,0,1,1,-1,-1};
constexpr int dy[] = {0,-1,0,1,1,-1,-1,1};
//}}}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

    int n;
    cin >> n;
    deque<int> dq1,dq2,res1,res2;
    int sum1 = 0,sum2 = 0;

    rep(i,n){
        int a;
        cin >> a;
        dq1.push_front(a);
        dq2.push_front(a);
    }

    sort(all(dq1));
    sort(all(dq2),greater<int>());

    res1.push_front(dq1.front());
    dq1.pop_front();

    rep(i,n){
        if(dq1.size() > 1){
            if(i % 2 == 0){
                res1.push_front(dq1.back());
                dq1.pop_back();
                res1.push_back(dq1.back());
                dq1.pop_back();
            }else{
                res1.push_front(dq1.front());
                dq1.pop_front();
                res1.push_back(dq1.front());
                dq1.pop_front();
            }
        }else if(!dq1.empty()){
            res1.push_front(dq1.front());
            dq1.pop_front();
        }else break;
    }

    res2.push_front(dq2.front());
    dq2.pop_front();

    rep(i,n){
        if(dq2.size() > 1){
            if(i % 2 == 0){
                res2.push_front(dq2.back());
                dq2.pop_back();
                res2.push_back(dq2.back());
                dq2.pop_back();
            }else{
                res2.push_front(dq2.front());
                dq2.pop_front();
                res2.push_back(dq2.front());
                dq2.pop_front();
            }
        }else if(!dq2.empty()){
            res2.push_front(dq2.front());
            dq2.pop_front();
        }else break;
    }

    rep(i,n-1){
        sum1 += abs(res1[i] - res1[i+1]);
        sum2 += abs(res2[i] - res2[i+1]);
    }

    cout << max(sum1,sum2) << '\n';

  	return 0;
}

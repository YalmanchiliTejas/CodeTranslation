#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1<<29
#define LINF LLONG_MAX/3
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define ALL(v) (v).begin(),(v).end()
#define debug(x) cerr<<#x<<":"<<x<<endl
#define debug2(x,y) cerr<<#x<<","<<#y":"<<x<<","<<y<<endl
#define CININIT cin.tie(0),ios::sync_with_stdio(false)
template<typename T> ostream& operator<<(ostream& os,const vector<T>& vec){ os << "["; for(const auto& v : vec){ os << v << ","; } os << "]"; return os; }

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main(){
    int n,a,b,c,x;
    while(cin>>n>>a>>b>>c>>x){
        if(n==0 and a==0 and b==0 and c==0 and x==0){
            break;
        }

        int frame = 0;
        vector<int> Y(n);
        rep(i,n) cin>>Y[i];
        rep(i,n){
            int y = Y[i];

            while(x!=y){
                ++frame;
                x = (a * x + b) % c;
                if(frame>10000){
                    cout << -1 << endl;
                    goto next;
                }
            }
            if(i!=n-1){
                frame++;
                x = (a * x + b) % c;
            }
        }
        cout << frame << endl;
next:;
    }
}
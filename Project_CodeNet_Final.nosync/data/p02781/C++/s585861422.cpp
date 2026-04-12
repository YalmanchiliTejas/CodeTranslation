#include<bits/stdc++.h>
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REPS(i,n) for(int i=1, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
#define INF 1e9
#define PI (acos(-1))
#define mod (int)1e9+7
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}
int main() {
    string n;
    cin>>n;
    int d=n.size();
    vector<int> v(d);
    int k;
    cin>>k;
    REP(i,d){
        v[i]=n[i]-'0';
    }
    int dp[101][2][101];//今見てる桁数,N未満フラグ,K=？
    Fill(dp,0);
    dp[0][0][0]=1;
    REP(i,d){
        REP(f,2){
            REP(j,d){
                for(int x=0; x<=(f ? 9 : v[i]); x++){
                    if(x!=0){
                        dp[i+1][f || x < v[i]][j+1]+=dp[i][f][j];
                    }
                    else {
                        dp[i+1][f || x < v[i]][j]+=dp[i][f][j];
                    }
                }
            }
        }
    }
    cout<<dp[d][0][k]+dp[d][1][k]<<endl;
    return 0;
}
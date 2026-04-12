#include <bits/stdc++.h>
#include <random>

using namespace std;
typedef long long int LL;
typedef long long int LLint;
typedef pair<int,int> intpair;
typedef pair<bool,bool> boolpair;
typedef pair<string,string> strpair;
typedef pair<LL,LL> LLpair;
typedef pair<double,double> doublepair;
typedef pair<float,float> floatpair;
typedef vector<int> intvector;
typedef vector<bool> boolvector;
typedef vector<string> strvector;
typedef vector<LL> LLvector;
typedef vector<double> doublevector;
typedef vector<float> floatvector;
#define wait(sec) usleep((sec) * 1000000)
#define ED return 0;
#define TEST cout << "OK" << endl;
#define UP(a,b) ((a+(b-1))/b)
#define SORT(vec) sort(vec.begin(),vec.end());
#define DOUBLECHANGE(count) cout << setprecision(count);
#define REV(vec) reverse(vec.begin(),vec.end());
#define ipow(x,y) LL(pow(x,y))
#define INF 999999999
const long long mod = 1000000007;

LL Pnum(LL N, LL X, vector<pair<LL,LL>> dp){
    //cout << "Calculate " << N << "," << X << " (dp[" << N << "] = " << dp[N].first << ")" << endl;
    LL ans = 0;
    if(N == 0){
        if(X >= 1){
            //cout << "Return 1" << endl;
            return 1;
        }
        else{
            //cout << "Return 0" << endl;
            return 0;
        }
    }

    if(X > dp[N].first/2){
        if(N != 0){
            ans += dp[N-1].second;
        }
        X -= (dp[N].first)/2;
        //cout << "X -> half (" << X << ")" << endl;
        if(X > 0){
            X--;
            ans++;
            ans += Pnum(N-1,X,dp);
            //cout << "Return " << ans << endl;
            return ans;
        }
        else{
            //cout << "Return " << ans << endl;
            return ans;
        }
    }
    else{
        if(X > 0){
            X--;
            ans += Pnum(N-1,X,dp);
            //cout << "Return " << ans << endl;
            return ans;
        }
        else{
            //cout << "Return " << ans << endl;
            return ans;
        }
    }
}

int main(){
//    random_device rnd;
//    mt19937 mt(rnd());
      cin.tie(0);
      ios::sync_with_stdio(false);
      LL N, X;
      cin >> N >> X;
      vector<pair<LL,LL>> dp (52,make_pair(1,1));
      for(int i = 1;i < 51;i++){
        dp[i].first = dp[i-1].first*2+3;
        dp[i].second = dp[i-1].second*2+1;
      }
      cout << Pnum(N,X,dp) << endl;
}

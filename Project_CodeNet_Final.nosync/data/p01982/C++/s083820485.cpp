#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define rep(i,b) FOR(i,0,b)
#define INF mugen
#define dump(x) cerr<<#x<<"="<<x<<endl
#define ALL(a) (a).begin(),(a).end()
#define EACH(e,v) for(auto& e:v)
#define SORT(v) sort(ALL(v))
#define PERM(v) SORT(v);for(bool c##p=1;c##p;c##p=next_permutation(ALL(v)))
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;
typedef pair<int,int> P;
template <class T> void chmin(T & a, T const & b) { if (b < a) a = b; }
template <class T> void chmax(T & a, T const & b) { if (b > a) a = b; }
template <typename T>
string to_string(const T &n){ostringstream stm;stm << n;return stm.str();}
inline int toInt(string s) { int v; istringstream sin(s); sin >> v; return v; }
using ll = long long;
const ll mod = 1000'000'007;
 
vector<int> vec;
signed main(){
    int n,l,r;
    while(cin>>n>>l>>r,n){
        vec.clear();
        rep(i,n){
            int a;cin>>a;
            vec.push_back(a);
        }

        int ans=0;


        int daiji=-1;
        for(int num=l;num<=r;num++){
            daiji=-1;
            for(int i=0;i<vec.size();i++){
                if(num%vec[i]==0){
                    daiji=i+1;
                    break;
                }
            }
            //dump(daiji);


            if(daiji==-1){
                if(vec.size()%2==0){
                    ans++;
                }
            }else if((daiji)%2==1){
                ans++;
            }
        }
        cout<<ans<<endl;

        

    }
 
}

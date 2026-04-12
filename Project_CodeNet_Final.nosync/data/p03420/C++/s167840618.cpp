//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
using in = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define yes cout<<"yes"<<endl
#define no cout<<"no"<<endl
const double PI=3.14159265358979323846;
const in MOD = 1000000007;
const in INF=1e18+7;
const int inf=1e9+7;
using P=pair<int,int>;
vector<int> dx={0,1,-1,0};
vector<int> dy={1,0,0,-1};



int main(){
ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
cout << fixed << setprecision(10);
    int n,k;
    cin>>n>>k;
    in cnt=0ll;
    if(k==0){
        cout<<(in)n*n<<endl;
        return 0;
    }
    REP(b,k+1,n+1){
        in a=(in)(n+1-b)/b;
        cnt +=(a+1ll)*(b-k);
        if((a+1)*b+k>n) continue;
        in thet=(in)n-k-(a+1)*b;
        cnt +=thet+1ll;
    }
    cout<<cnt<<endl;
}
//./problem.exe
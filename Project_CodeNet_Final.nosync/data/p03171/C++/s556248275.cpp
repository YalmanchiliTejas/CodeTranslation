#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

//using namespace __gnu_pbds;
using namespace std;

typedef  long long ll;
typedef long double ld;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define endl "\n"
#define ioss ios::sync_with_stdio(0);cin.tie(0);
#define pb push_back
#define eb emplace_back



double startTime;
double gct()//get_current_time
{
    return ((double)clock()-startTime)/CLOCKS_PER_SEC;
}

void suraj();

int main()
{
    startTime=(double)clock();
    //freopen("input.txt","r",stdin);
    //freopen("output.txt,"w",stdout);
    //ioss
    //int t;cin>>t;while(t--)
    suraj();
    //suraj2();
    //suraj3();
    //suraj4();
    return 0;
}

































const int nax=3005;
const int aax=1e9;

ll dp[nax][nax];//dp[i][j] is equal to the optimal value of (x-y) if the remaining array has index from i to j
void suraj(){
int n;scanf("%d",&n);
vector<ll>a(n);for(ll &i:a)scanf("%lld",&i);
for(int l=n-1;l>=0;l--){
    for(int r=l;r<n;r++){
        if(l==r)
            dp[l][r]=a[l];
        else{
            dp[l][r]=max(a[l]-dp[l+1][r],a[r]-dp[l][r-1]);
        }
    }
}


cout<<dp[0][n-1]<<endl;



}//












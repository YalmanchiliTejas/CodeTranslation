#include <bits/stdc++.h>
using namespace std;
#define rep(i,k,n) for(int i = k; i < n; i++)  
#define repp(i,k,n) for(int i = k; i <= n; i++) 
#define per(i,k,n) for(int i = k; i >= n; i--)

#define int long long
#define all(a) a.begin(),a.end()       

#define pb push_back
typedef long long ll; 
typedef pair<int, int> ii;
typedef pair<int,ii > iii; 
typedef vector<ii> vii;
typedef vector<char> vchar;
typedef vector<int> vi;
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound

#define mem(a, b) memset(a, b, sizeof(a));
#define mem0(a) memset(a, 0, sizeof(a));

#define INF 1000000000
//#define mod 998244353
#define mod 1000000007
#define endl "\n"


   //=\/=\/=\/=\/=\/=\/=\/=\/=\/=\        Jai Hind Dosto        /=\/=\/=\/=\/=\/=\/=\/=\/=\/=\/=\/=\/=\\
  //=\/=\/=\/=\                    ̿̿ ̿̿ ̿̿ ̿'̿'\̵͇̿̿\з= ( ▀ ͜͞ʖ▀) =ε/̵͇̿̿/’̿’̿ ̿ ̿̿ ̿̿ ̿̿                             /=\/=\/=\/=\\
 //=\/=\/=\/=\                                                                               /=\/=\/=\/=\\
//=\/=\/=\/=\/=\/=\/=\/=\/=\/=\/=\/=\/=\/=\/=\/=\/=\/=\/=\/=\/=\/=\/=\/=\/=\/=\/=\/=\/=\/=\/=\/=\/=\/=\/=\\



int modPow(int a, int b);           

                
void solve(){
    int n ;
    cin >> n ;
    if(n>=30)cout <<"Yes";
    else cout << "No";
    
}






signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //cout << fixed;
    //cout <<setprecision(6);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
   // int test=1; cin >> test; while(test--)
    solve();
}

int modPow(int a, int b){
    if(b==0)return 1;
    if(b%2==0){
        int x = a*a;
        x%=mod;
        return modPow(x,b/2);
    }
    return (a*modPow(a,b-1))%mod;
}



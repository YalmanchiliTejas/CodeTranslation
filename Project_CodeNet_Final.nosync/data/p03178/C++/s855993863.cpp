/***
**   AUTHOR::ASHUTOSH MOUDGIL
***/


#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#define F first
#define S second
#define int long long
//#define ll long long
#define all(x) x.begin(),x.end()
#define rsort(x) sort(all(x)); reverse(all(x));
#define endl '\n'
#define vi vector<int>
#define vlli vector<long long>
#define pii pair<int,int>
#define mod 1000000007
#define LMAX 1e18
#define deb(x) cout<<#x<<" : "<<x<<endl;
#define PI 3.141592654
#define deb1(x) cout << #x <<"="<< x <<endl;
#define deb2(x,y) cout << #x <<"="<<x<<", "<<#y<<"="<<y <<endl;
#define deb3(x,y,z) cout << #x <<"="<<x<<", "<<#y<<"="<<y <<", "<<#z<<"="<<z<<endl;
#define deb4(x,y,z,a) cout << #x <<"="<<x<<", "<<#y<<"="<<y <<", "<<#z<<"="<<z<< ", "<<#a <<"="<<a << endl;
#define debarr(x) cout << #x<<"::"<<endl;for(int i : x){cout << i <<" ";} cout <<endl;

inline void add(int& a, int b){a = (a+b); if(a>=mod)a-=mod;}
inline void sub(int& a, int b){a = a-b; if(a<0)a+=mod;}
inline void mul(int& a, int b){a = (a*b)%mod;}

int d;
vector<vi> dp(101,vi(2));
string k;


void mymain(){
    cin >> k >> d;
    int n = k.size();

    dp[0][0] = 1;

    for(int i=0;i<n;i++){
        vector<vi> ndp(101,vi(2));
        for(int s=0;s<d;s++){
            for(int kk=0;kk<10;kk++){
                if(kk<k[i]-'0'){
                    add(ndp[(s+kk)%d][1] ,(dp[s][0]+dp[s][1])%mod);

                }else if(kk == k[i]-'0'){
                    add(ndp[(s+kk)%d][0], dp[s][0]);
                    add(ndp[(s+kk)%d][1], dp[s][1]);
                }else{
                    add(ndp[(s+kk)%d][1], dp[s][1]);
                }
            }
        }
        //deb3(i,ndp[0][0],ndp[0][1])
        dp = ndp;
    }

    add(dp[0][0],dp[0][1]);
    int ans = dp[0][0];
    sub(ans,1);
    cout << ans << endl;

}

signed main(){
IOS;
///freopen("input.txt", "r", stdin);
///freopen("output.txt", "w", stdout);
int t=1;
//cin>>t;

for(int tt=0;tt<t;tt++){
   ///cout << "Case #" << tt+1 <<": ";
   mymain();
   }
return 0;
}
/*

*/

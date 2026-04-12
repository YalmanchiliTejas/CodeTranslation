#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define ld long double
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using P=pair<long long,long long>;
#define rep(i,n) for(long long i=0; i<(long long)n; i++)
#define req(i,n) for(long long i=n-1; i>=0; i--)
#define range(i,a,b) for(long long i=a; i<b; i++)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((long long)(x).size())
#define COUT(x) cout << x << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define onBoard(y,x) (y>=0 && y<h && x>=0 && x<w)
#define vint vector<int>
#define pri_que priority_queue
#define vvint vector<vector<int>>
#define vstr vector<string>
#define vp vector<pair<int,int>>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define SUM(x) accumulate(x.begin(),x.end(),0)
#define MAX(x) *max_element(x.begin(),x.end())
#define MIN(x) *min_element(x.begin(),x.end())
#define couty cout<<"Yes"<<endl
#define coutn cout<<"No"<<endl
#define coutY cout<<"YES"<<endl
#define coutN cout<<"NO"<<endl
#define yn(x) cout<<(x?"Yes":"No")<<endl
#define YN(x) cout<<(x?"YES":"NO")<<endl
long long gcd(long long a,long long b){return b?gcd(b,a%b):a;}
long long lcm(long long a, long long b){return a/gcd(a,b)*b;}
const long long dx[8]={1,0,-1,0,1,-1,-1,1};
const long long dy[8]={0,1,0,-1,1,1,-1,-1};
const long long INF = 1e12;
const long long MOD = 1e9+7;

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout<<fixed<<setprecision(15);

    int h,w; cin >> h>> w;
    vector<vector<char>> s(h+2,vector<char>(w+2,'.'));
    range(i,1,h+1){
        range(j,1,w+1){
            cin >> s[i][j];
        }
    }

    int i=1,j=1;
    while(true){
            if(i==h && j==w && s[i][j]=='#'){
                rep(k,4){
                    if(s[i+dy[k]][j+dx[k]]=='#'){
                        cout<<"Impossible"<<endl;
                    return 0;
                    }
                }
                cout<<"Possible"<<endl;
                return 0;
            }
            bool l=false,r=false,u=false,d=false;
            if(s[i][j+1]=='#') r=true;
            if(s[i][j-1]=='#') l=true;
            if(s[i+1][j]=='#') d=true;
            if(s[i-1][j]=='#') u=true;

            if(l==1 || u==1 || (r==1&&d==1)){
                cout<<"Impossible"<<endl;
                return 0;
            }
            s[i][j]='.';
            if(r==1) j++;
            if(d==1) i++;
        
    }
}
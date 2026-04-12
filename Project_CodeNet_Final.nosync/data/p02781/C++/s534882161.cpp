#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i = 0; i < (n); ++i)
#define repA(i, a, n) for(int  i = a; i <= (n); ++i)
#define all(x) x.begin(), x.end()
#define sz(x) (int) (x).size()
#define fill(a) memset(a, 0, sizeof(a))
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
#define endl '\n'
#define init(n) int n;cin>>n;int a[n];rep(i,n)cin>>a[i];
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<long long int> vll;
typedef vector<pii> vii;
ll p1=1000000007;
int n;
int main() {
   
    cin.sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    int T=1;
    // cin>>T;
    while(T--) {
        string s;cin>>s;
        int n=s.size();
        int k;cin>>k;
        ll ans=0;
        if(k==1){
            for(int i=1;i<n;i++){
                ans=ans+9;
            }
            int c=s[0]-'0';
            for(int i=1;i<=c;i++)ans++;
        }
        else if(k==2){
            for(int i=2;i<n;i++){
                ans=ans+9*9*(i-1);
            }
            string temp;temp.resize(n);
            for(int i=1;i<=9;i++){
                temp[0]=i+'0';
                for(int j=1;j<n;j++){
                    for(int k=1;k<=9;k++){
                        temp[j]=k+'0';
                        if(temp<=s)ans++;
                    }
                    temp[j]='0';
                }
            }
        }
        else{
            for(int i=3;i<n;i++){
                ans=ans+(9*9*9*(i-1)*(i-2))/2;
            }
            string temp;temp.resize(n);
            for(int i=1;i<=9;i++){
                temp[0]=i+'0';
                for(int j=1;j<n;j++){
                    for(int k=j+1;k<n;k++){
                        for(int l=1;l<=9;l++){
                            for(int m=1;m<=9;m++){
                                temp[j]=l+'0';
                                temp[k]=m+'0';
                                if(temp<=s)ans++;
                            }
                        }
                        temp[k]='0';
                    }
                    temp[j]='0';
                }
            }
        }
        cout<<ans;
    } 
    return 0;   
}
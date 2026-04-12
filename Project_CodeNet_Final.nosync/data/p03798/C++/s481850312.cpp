#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
// const bool debug=true;
const bool debug=false;
#define DEBUG if(debug==true)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MOD = 1000000007;

int main(void) {
    int n;
    string s;
    cin>>n>>s;
    int res[n];
    rep(i,n)res[i]=-1;
    const char circle = 'o';
    const char cross = 'x';
    bool flg=false;
    DEBUG{cout << s[0] << endl;}
    rep(r0,2){
        rep(r1,2){
            DEBUG{cout << "0 : " << r0 << " 1 : " << r1 << endl;}
            res[0]=r0;
            res[1]=r1;
            for(int i=1;i<n-1;i++){
                if(s[i]==circle){
                    if(res[i]){res[i+1]=1-res[i-1];}
                    else {res[i+1]=res[i-1];}
                }else{
                    if(!res[i]){res[i+1]=1-res[i-1];}
                    else {res[i+1]=res[i-1];}
                }
            }
            DEBUG{cout << res[0] << res[n-2] << res[n-1] << endl;}
            DEBUG{cout << "s[n-1] : " << int(s[n-1]) << endl;}
            DEBUG{cout << "flg : " << (res[0]==res[n-2]&&(res[n-1]&&int(s[n-1])==cross||!res[n-1]&&int(s[n-1])==circle)) << endl;}
            flg = ((res[1]==res[n-1]&&(res[0]&&s[0]==cross||!res[0]&&s[0]==circle)) ||
                (res[1]!=res[n-1]&&(res[0]&&s[0]==circle||!res[0]&&s[0]==cross))) &&
                ((res[0]==res[n-2]&&(res[n-1]&&s[n-1]==cross||!res[n-1]&&s[n-1]==circle)) ||
                (res[0]!=res[n-2]&&(res[n-1]&&s[n-1]==circle||!res[n-1]&&s[n-1]==cross)));
            DEBUG{cout << "flag : " << flg << endl;}
            if(flg){
                break;
            }
        }
        if(flg){
            break;
        }
    }
    if(flg){
        rep(i,n){
            cout << (res[i] ? 'W' : 'S');
        }
        cout<<endl;
    }else {
        cout << -1 << endl;
    }
    return 0;
}

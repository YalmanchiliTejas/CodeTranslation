#include<bits/stdc++.h>
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define srep(i,n,m) for(int i=n;i<m;i++)
#define elif else if
#define INF 1000000007
using namespace std;
int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int m,n,aa[110000][10],k,cnt=0,ab[10];
pair<int,int> p[220000];
string s,ss[220000],x;
char c;
signed main(){
    cin>>s;
    if(s[0]==s[1]&&s[1]==s[2]){
        cout<<"No";
    }else{
        cout<<"Yes";
    }
}
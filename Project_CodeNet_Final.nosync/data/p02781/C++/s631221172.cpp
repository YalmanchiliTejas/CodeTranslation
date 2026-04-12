#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#include <cstdlib> 
#include <math.h>
#define gap cout<<endl;
#define FOR(I, A, B) for (int I = (A); I <= (B); I++)
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef pair< int,int > ii;
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fo(i,n) for(int i=0;i<n;i++)
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c)).begin() i = (c).begin(); i != (c).end(); i++)
#define INF 1<<30
#define present(c,x) ((c).find(x) != (c).end())
const int N=20000;
std::vector<int> fact(3000,1);
int k;
string n;
int pow(int a, int b)
{
    int ans=1;
    while(b)
    {
        if(b&1)
            ans=(ans*a);
        b/=2;
        a=(a*a);
    }
    return ans;
}
 
 
 
 
int nCr(int x, int y)
{
    if(y>x)
        return 0;
    if(y==0) return 1;
    if(x==y) return 1;
    if(x==0&&y==0) return 1;
    
     //cout<<x<<" "<<y<<endl;
    if(y==1) return x;
    if(y==2){
        return x*(x-1)/(2);
    }
    if(y==3){
        return x*(x-1)*(x-2)/(6);
    }
    return 1;
    //cout<<fact[]<<endl;
    //if(num2==0) cout<<x<<" "<<y<<endl;
    
}
int fu(string s,int k){
    if(k<=0) return 1;
    int len=sz(s);
    if(len==0) return 0;
    int tmp,tmp2,tmp3;
    tmp=tmp3=tmp2=0;
    //cout<<tmp<<endl;
    if(k>len) return 0;
    if(s[0]=='0') return fu(s.substr(1),k);
    if(s[0]>'0') tmp=nCr(len-1,k)*(pow(9,k));
    tmp3=(s[0]-'0'-1)*(nCr(len-1,k-1))*(pow(9,k-1));
    
    if(len>=1) {string s2=s.substr(1);
         tmp2=(fu(s2,k-1));}
     
 
    return tmp2+tmp3+tmp;
 
}
 
 
int main(){
    
     
    cin>>n>>k; 
    int ans=fu(n,k);
    cout<<ans<<endl;
}
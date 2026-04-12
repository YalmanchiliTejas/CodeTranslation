#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
#define vec(s) vector<s>;
#define vvec(s) vector<vector<s>> ;
typedef vector<lli> vi;
typedef vector<vi> vvi;
typedef pair<lli,lli> pii;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YN(x) cout<<(bool x?"Yes":"No")<<endl;
#define out(s) cout<<s<<endl;
#define pb(s) push_back(s);
#define sp " ";
#define INF 10000000000
#define all(s) s.begin(),s.end()
void vout(vector<int> v){
    for(int i=0;i<v.size();i++)
    cout<<v.at(i)<<endl;
}
int main(){
    int a,b,c,x,y;
    lli ans=0;
    cin>>a>>b>>c>>x>>y;
    if(a+b>2*c){
        ans+=min(x,y)*2*c;
        if(x>y){
            if(abs(x-y)*a<abs(x-y)*2*c){
                ans+=abs(x-y)*a;
            }
            else{
                ans+=abs(x-y)*2*c;
            }
        }
        else{
            if(abs(x-y)*b<abs(x-y)*2*c){
                ans+=abs(x-y)*b;
            }
            else{
                ans+=abs(x-y)*2*c;
            }
        }
    }
    else{
        ans+=a*x;
        ans+=b*y;
    }
    out(ans);
}
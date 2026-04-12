///বিসমিল্লাহির_রহমানির_রহীম
#include<bits/stdc++.h>
#define     pie                          acos(-1)
#define     N                            2000005
#define     ESP                          1e-9
#define     pii                          pair<int,int>
#define     vi                           vector<int>
#define     vl                           vector<ll>
#define     pb                           push_back
#define     pp                           pop_back
#define     ff                           first
#define     ss                           second
#define     nl                           "\n"
#define     MOD                          1000000007
#define     sp                           " "
#define     CLR(a)                       memset(a,0,sizeof(a))
#define     SET(a)                       memset(a,-1,sizeof(a))
#define     mk                           make_pair
#define     ALL(x)                       x.begin(),x.end()
using namespace std;
int dx[]={0,0,1,-1,-1,-1,1,1};
int dy[]={1,-1,0,0,-1,1,1,-1};
typedef long long ll;
typedef long double ld;
int main(){
    ios_base::sync_with_stdio(false); cout.setf(ios::fixed); cout.precision(10);
    cin.tie(nullptr);  cout.tie(nullptr);
    // freopen ("output.txt","w",stdout);
    // freopen ("input.txt","r",stdin);
    int n;
    string s;
    int k;
    cin>>n>>s>>k;
    for(int i=0;i<n;i++){
        if(s[k-1]!=s[i]) s[i]='*';
    }
    cout<<s<<endl;


    return 0;
}

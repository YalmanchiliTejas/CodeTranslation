#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <bitset>
#include <cmath>
#include <string>
#include <fstream>
#define FI first
#define SE second
#define VE vector<int>
#define PB push_back
#define PA pair<int,int>
#define MA make_pair
#define LL long long
#define LI long int
#define LLI long long int
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ROF(i,a,b) for(int i=b-1;i>=a;i--)
#define YES(i) cout<<(i?"YES":"NO")<<endl
#define Yes(i) cout<<(i?"Yes":"No")<<endl
#define POS(i) cout<<(i?"POSSIBLE":"IMPOSSIBLE")<<endl
using namespace std;
//
const int INF=1e9+7;
const int LINF=1e18;
const int MOD=1e9+7;
//
int main(){
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    int A=min(a,2*c),B=min(b,2*c),AB=min(a+b,2*c);
    int ans;
    if(x>=y){
        ans=(x-y)*A+y*AB;
    }else{
        ans=(y-x)*B+x*AB;
    }
    cout<<ans<<endl;

}
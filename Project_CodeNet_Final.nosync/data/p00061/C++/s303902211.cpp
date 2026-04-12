#include <bits/stdc++.h>
#define rep(i,j,k) for(int i=(int)j;i<(int)k;i++)
#define itrep(x) for(auto it=(x).begin();it!=(x).end();it++)
#define Sort(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define vi vector<int>
#define INF (int)1e9
#define INFL 1e18
//#define MOD 1000000007
#define pb push_back
#define MP make_pair
#define PI 3.1415926535
typedef long long int ll;
typedef std::pair<int,int> P;
int D=1;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

using namespace std;

int main(){
    vector<P> v;
    char c;
    int a,b;
    while(cin>>a>>c>>b && a){
        v.pb(MP(b,a));
    }
    sort(v.rbegin(),v.rend());
    
    int n;
    while(cin>>n){
        int count=1;
        for(int i=0;i<v.size();i++){
            if(v[i].se==n){
                cout<<count<<endl;
                goto AWAY;
            }
            while(v[i].fi==v[i+1].fi){
                i++;
                if(v[i].se==n){
                    cout<<count<<endl;
                    goto AWAY;
                }
            }
            count++;
        }
        AWAY:;
    }
    
    return 0;
}


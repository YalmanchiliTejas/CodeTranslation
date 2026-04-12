#include <bits/stdc++.h>
#define SORT(x) sort((x).begin(),(x).end())
#define ALL(x) (x).begin(),(x).end()
#define rep(i, n) for(int i = 0; i < n; i++)
#define reps(i, m, n) for(int i = m; i < n; i++)
#define repr(i, m, n) for(int i = m; i >= n; i--)
#define db(x) cout<<#x<<"="<<x<<endl
template<class T>bool maxi(T &a,const T &b){if(a<b){ a=b; return 1;} return 0;}
template<class T>bool mini(T &a,const T &b){if(b<a){ a=b; return 1;} return 0;}
#define y0 y3487465 //y1 j0 j1
#define INF2 4000000000000000037
#define INF 1000000007
#define PI (acos(-1))
#define MOD 1000000007
#define EPS 1e(-9);
using namespace std;
typedef long long ll;



void Main(){

    ll N,X; cin>>N>>X;
    ll layer[51];
    layer[0]=1;
    rep(i,50){
        layer[i+1]=layer[i]*2+3;
    }

    ll putty=0;
    ll compburg=0;
    ll surpluslayer=X;

    repr(i,N-1,0){

        putty+=compburg;
        compburg*=2;

        if(surpluslayer==0) surpluslayer=0;
        else if(surpluslayer<layer[i]+1) surpluslayer-=1;
        else if(surpluslayer==layer[i]+1) {
            ++compburg;
            surpluslayer=0;
        }
        else if(surpluslayer<layer[i]*2+2){
            ++putty;
            ++compburg;
            surpluslayer-=layer[i]+2;
        }
        else{
            ++putty;
            compburg+=2;
            surpluslayer=0;
        }
    }

    cout<< putty+compburg <<"\n";
}

//-----------------------------------
int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
}
//-----------------------------------

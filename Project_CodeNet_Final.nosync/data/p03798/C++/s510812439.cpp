#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1000000000
#define mod 1000000007
typedef long long ll;
const ll LINF = 1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
//0と1を決めたら2が決まって3が決まって...
//01をSS,SW,WS,WW全部試してnとぐるっとやって矛盾が無ければいいのでは

main(){
    int n;
    string saying;
    cin>>n;
    cin>>saying;

    string YATTE_TRY[4]={"SS","SW","WS","WW"};

    for(int YT=0;YT<4;YT++){
        string ans=YATTE_TRY[YT];
        for(int i=2;i<n;i++){
            if(saying[i-1]=='o'){
                if(ans[i-1]=='S'){
                    //羊がoという
                    if(ans[i-2]=='S')   ans+="S";
                    else                ans+="W";
                }
                else{
                    //狼がoという
                    if(ans[i-2]=='S')   ans+="W";
                    else                ans+="S";
                }
            }
            else{
                if(ans[i-1]=='S'){
                    //羊がxという
                    if(ans[i-2]=='S')   ans+="W";
                    else                ans+="S";
                }
                else{
                    //狼がxという
                    if(ans[i-2]=='S')   ans+="S";
                    else                ans+="W";
                }
            }
        }
        //0とn-1がくっつく部分で矛盾がないか
        bool f1=false,f2=false;
        if(ans[n-1]=='S'){
            if(saying[n-1]=='o'){
                if(ans[n-2]==ans[0]){
                    f1=true;
                }
            }
            else{
                if(ans[n-2]!=ans[0]){
                    f1=true;
                }
            }
        }
        else{
            if(saying[n-1]=='o'){
                if(ans[n-2]!=ans[0]){
                    f1=true;
                }
            }
            else{
                if(ans[n-2]==ans[0]){
                    f1=true;
                }
            }
        }
        //f1で最後の動物の言い分が正しいか判定
        //f2で0の動物の言い分が正しいか判定
        if(ans[0]=='S'){
            if(saying[0]=='o'){
                if(ans[1]==ans[n-1]){
                    f2=true;
                }
            }
            else{
                if(ans[1]!=ans[n-1]){
                    f2=true;
                }
            }
        }
        else{
            if(saying[0]=='x'){
                if(ans[1]==ans[n-1]){
                    f2=true;
                }
            }
            else{
                if(ans[1]!=ans[n-1]){
                    f2=true;
                }
            }
        }
        if(f1&&f2){cout<<ans<<endl;return 0;}
    }
    cout<<-1<<endl;
    return 0;
}
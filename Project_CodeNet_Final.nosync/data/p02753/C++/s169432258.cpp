#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#include<map>
#include<tuple>
#include<cmath>


#define MOD 1000000007
#define rep(i,k,N) for(int i=k;i<N;i++)
#define MP make_pair
#define MT make_tuple //tie,make_tuple は別物
#define PB push_back

typedef long long ll;

using namespace std;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main(){
    string S;
    cin>>S;
    bool Aans =true, Bans=true;
    rep(i,0,3){
        if(S[i]=='A'){
            Bans =false;
        }
        else{
            Aans =false;
        }
    }
    if(Aans || Bans){
        cout <<"No";
    }
    else cout <<"Yes";
    return 0;
}
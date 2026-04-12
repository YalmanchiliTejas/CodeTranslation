#include <iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<stack>
#include <queue>
#include<algorithm>
typedef long long int ll;
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define REP(i,n) for (int i=0;i<(n);i++)
#define EREP(i,n) for (int i=1;i<=(n);i++)
#define EVEL 1
#ifndef EVEL
#define DEB(X) cout << #X << ":" <<X<<" " ;
#define TF(f) f ? cout<<"true  " : cout<<"false ";
#define END cout<<"\n";
#else
#define DEB(X) {}
#define TF(f) {}
#define END {}
#endif
const ll MOD = 1000000007;
    ll N,sum=0,c;
    std::vector<std::string> S;
      string saw;
    string as="",ans="";
    int m[30];
    int yui[30];
int main(){
    ios_base::sync_with_stdio(false);
    cin>>N;
    REP(i,N){
        string s;

        cin>>s;
        for(auto x:s){
            yui[(int)x-(int)'a']++;
                DEB((int)x-(int)'a') DEB(yui[(int)x-(int)'a']) END
        }
        REP(j,(int)'z'-(int)'a'+1){
            if(i==0){
                m[j]=yui[j];
            }else{
                DEB(j)DEB(m[j])DEB(yui[j])END
                m[j]=min(yui[j],m[j]);
            }
        }
        REP(k,30)yui[k]=0;
    }
    REP(i,(int)'z'-(int)'a'+1){
        REP(j,m[i]){
            cout<<(char)(i+(int)'a');
        }
    }
    cout<<endl;
    //cout<<ans;
    return 0;
}

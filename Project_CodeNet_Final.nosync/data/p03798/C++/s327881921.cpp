#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define INF 1000000000000000009
//#define INF 9223372036854775807
typedef long long ll;
#define REP(i,n) for(int i=0;i<(n);++i)
#define OREP(i,n) for(int i=1;i<=(n);++i)
#define RREP(i,n) for(int i=(n)-1;i>=0;--i)
#define rollcall cout<<"I'm Sucu."<<endl;
#define YES(s) s?cout << "YES" << endl:cout << "NO" << endl
#define Yes(s) s?cout << "Yes" << endl:cout << "No" << endl
#define Taka(s) s?cout << "Takahashi" << endl:cout << "Aoki" << endl
#define out(s,t,u) s?cout << t << endl:cout << u << endl
#define int ll
#define Endl endl
//#define P pair<int,int>

signed main(){
    int N;
    string S,T;
    char r[2]={'S','W'};
    cin >> N;
    cin >> S;
    
    REP(j,4){
        T.clear();
        int p=j/2,q=j%2;
        //pは1番目,qは2番目
        T+=r[p];
        T+=r[q];
        REP(i,N-1){
            if(i==0)continue;
            if((S[i]=='x'&&T[i]=='S')||(S[i]=='o'&&T[i]=='W')){
                if(T[i-1]=='S'){
                    T+="W";
                }else{
                    T+="S";
                }
            }else{
               T+=T[i-1];
            }
        }
        //cout << T << endl;
        bool mujun=false;
        REP(i,N){
            if(T[i]=='S'){
                if((S[i]=='o'&&T[(i-1+N)%N]!=T[(i+1)%N])||(S[i]=='x'&&T[(i-1+N)%N]==T[(i+1)%N])){
                    mujun=true;
                }
            }else{
                if((S[i]=='o'&&T[(i-1+N)%N]==T[(i+1)%N])||(S[i]=='x'&&T[(i-1+N)%N]!=T[(i+1)%N])){
                    mujun=true;
                }
            }
        }
        if(mujun==false){
            cout << T << endl;
            return 0;
        }
    }
    cout << -1 << endl;
	return 0;
}
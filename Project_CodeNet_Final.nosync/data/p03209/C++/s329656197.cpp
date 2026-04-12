#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
//#define INF 10000000000000009
#define INF 9223372036854775807
typedef long long ll;
#define REP(i,n) for(int i=0;i<(n);++i)
#define OREP(i,n) for(int i=1;i<=(n);++i)
#define ORREP(i,n) for(int i=(n);i>=1;--i)
#define ZREP(i,n) for(int i=1;i<(n);++i)
#define RREP(i,n) for(int i=(n)-1;i>=0;--i)
#define rollcall cout<<"I'm Sucu."<<endl;
#define YES(s) s?cout << "YES" << endl:cout << "NO" << endl
#define Yes(s) s?cout << "Yes" << endl:cout << "No" << endl
#define Taka(s) s?cout << "Takahashi" << endl:cout << "Aoki" << endl
#define out(s,t,u) s?cout << t << endl:cout << u << endl
#define int ll
#define Endl endl

int Ans=0;

//レベルLの
//バーガーの全長:4*2^L-3
//バーガーに含まれるバンズ:2*2^L-1

int eat(int R,int L){//レベルLのバーガーの下からR枚を食べる
    //cout << R << " " << L << endl;
    if(L==0){
        Ans++;//レベル0のバーガーはパティ1枚
        return R-1;
    }
    int f=1;REP(i,L){f*=2;}
    int Len=((2*f)-3);//レベルL-1バーガーの長さとパティ数
    int Pat=(f-1);
    //cout << Len << " " << Pat << endl;
    R--;//上バンズ
    if(R==0)return 0;
    if(R<Len){//上バーガー
        R=eat(R,L-1);
    }else{
        R-=Len;
        Ans+=Pat;
    }
    if(R==0)return 0;
    R--;Ans++;//中パティ
    if(R==0)return 0;
    if(R<=Len){//下バーガー
        R=eat(R,L-1);
    }else{
        R-=Len;
        Ans+=Pat;
    }
    if(R==0)return 0;
    
    R--;//下バンズ
    return R;
}

signed main(){
    int N,X;
    cin >> N >> X;
    //cout << (1<<50ll) << endl;
    eat(X,N);
    cout << Ans << endl;
    return 0;
}   

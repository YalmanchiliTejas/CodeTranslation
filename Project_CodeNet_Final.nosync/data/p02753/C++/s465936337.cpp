#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
#define INF 1145141919810893364
//#define INF 810114514
//#define PI 3.141592653589
typedef pair<int,int> PP;
typedef long long ll;
#define int ll
#define setdouble setprecision
#define REP(i,n) for(int i=0;i<(n);++i)
#define OREP(i,n) for(int i=1;i<=(n);++i)
#define RREP(i,n) for(int i=(n)-1;i>=0;--i)
#define GOODBYE do { cout << "0" << endl; return 0; } while (false)
#define MM <<" "<<
#define Endl endl


signed main(void){
    string S;
    cin >> S;
    int b=0;
    REP(i,3){
        if(S[i]=='B')b++;
    }
    if(b==1 || b==2){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}


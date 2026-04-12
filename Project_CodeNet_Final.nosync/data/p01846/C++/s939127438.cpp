#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
//#define MOD 998244353
#define INF 1145141919810893364
typedef pair<int,int> PP;
typedef long long ll;
#define int ll
#define setdouble setprecision
#define REP(i,n) for(int i=0;i<(n);++i)
#define OREP(i,n) for(int i=1;i<=(n);++i)
#define RREP(i,n) for(int i=(n)-1;i>=0;--i)
#define GOODBYE cout << -1 << endl;return 0
#define MM <<" "<<
#define Endl endl

signed main(void){
    string S;
    int ope[4];
    int table[10][10];
    while(1){
        cin >> S;
        if(S=="#"){
            return 0;
        }
        REP(i,4){
            cin >> ope[i];
            ope[i]--;
        }
        REP(i,10){
            REP(j,10){
                table[i][j]=0;
            }
        }
        int nowi=0,nowj=0;
        REP(i,S.size()){
            if(S[i]=='b'){
                table[nowi][nowj]=1;
                nowj++;
            }else if(S[i]=='/'){
                nowj=0;
                nowi++;
            }else{
                nowj+=(int)(S[i]-'0');
            }
        }
        table[ope[0]][ope[1]]=0;
        table[ope[2]][ope[3]]=1;
        
        //REP(i,nowi+1){REP(j,nowj){cout << table[i][j];}cout << endl;}
        
        int str=0;
        REP(i,nowi+1){
            REP(j,nowj){
                if(table[i][j]==1 || j+1==nowj){
                    if(table[i][j]==0){
                        str++;
                    }
                    if(str!=0){
                        cout << str;
                    }
                    if(table[i][j]==1){
                        cout << "b";
                    }
                    str=0;
                }else{
                    str++;
                }
            }
            if(i!=nowi){
                cout << "/";
            }
        }
        cout << endl;
    }
    return 0;
}



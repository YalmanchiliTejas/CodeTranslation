#include <bits/stdc++.h> 
 
using namespace std;
 
//typedef
//------------------------------------------
typedef pair<int, int> PII;
typedef pair<long, long> PLL;
typedef long long LL;
//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define PB emplace_back
#define MP make_pair 
#define SZ(a) int((a).size())
//repetition
//------------------------------------------
#define FOR(i,a,b) for(LL i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define SORT(c) sort((c).begin(),(c).end())
//constant
//--------------------------------------------
//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))
 
bool m[10][10];

int main(){
    CLR(m);
    int N,M;
    cin>>N>>M;
    REP(i,M){
        int a,b;
        cin>>a>>b;a--;b--;
        m[a][b]=m[b][a]=1;
    }
    vector<int>vec;
    REP(i,N-1)vec.PB(i+1);
    int res=0;
    do{
        bool flag=true;
        if(!m[0][vec[0]])continue;
        REP(i,SZ(vec)-1){
            if(!m[vec[i]][vec[i+1]]){
                flag=false;break;
            }
        }
        res+=flag;
    }while(next_permutation(ALL(vec)));
    cout<<res<<endl;
    return 0;
}

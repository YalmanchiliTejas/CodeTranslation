#include <bits/stdc++.h> 
#include <chrono>
using namespace std;
 
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}
 
 
//typedef
//------------------------------------------
typedef pair<int, int> PII;
typedef long long LL;
typedef pair<LL, LL> PLL;
 
//container util
//------------------------------------------
#define PB emplace_back
#define MP make_pair 
#define SZ(a) int((a).size())
//repetition
//------------------------------------------
#define FOR(i,a,b) for(LL i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define SORT(c) sort((c).begin(),(c).end())
#define ALL(a)  (a).begin(),(a).end()
//constant
//--------------------------------------------
//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))
int main(){
    LL N,X,M;
    cin>>N>>X>>M;
    LL A=X;
    vector<LL>prel,posl;
    prel.PB(A);
    vector<LL>loop;
    set<LL>chk;
    LL tmpA;
    REP(i,N){
        tmpA=A*A%M;
        if(tmpA==0){
            LL res=prel[0];
            REP(ii,SZ(loop))res+=loop[ii];
            cout<<res<<endl;
            return 0;
        }
        if(chk.find(tmpA)!=chk.end())break;
        loop.PB(tmpA);
        chk.insert(tmpA);
        A=tmpA;
    }
    bool flag=false;
    REP(i,SZ(loop)){
        if(loop[i]==tmpA)flag=true;
        if(!flag)prel.PB(loop[i]);
        else posl.PB(loop[i]);
    }
    LL poslsum=0;
    REP(i,SZ(posl))poslsum+=posl[i];
    LL res=0;
    if(N<=SZ(prel)){
        REP(i,N)res+=prel[i];
        cout<<res<<endl;
        return 0;
    }else{
        REP(i,SZ(prel))res+=prel[i];
    }
    res+=poslsum*((N-SZ(prel))/SZ(posl));
    REP(i,((N-SZ(prel))%SZ(posl)))res+=posl[i];
    cout<<res<<endl;
    return 0;
}
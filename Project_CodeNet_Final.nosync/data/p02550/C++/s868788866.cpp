// {{{ Boilerplate Code <--------------------------------------------------
// vim:filetype=cpp:foldmethod=marker:foldmarker={{{,}}}

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

#define FOR(I,A,B) for(long long I = (A); I < (B); ++I)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

// }}}

long long solve(long long N,long long X,long long M){
        int prev[200000];
        FOR(i,0,M+1){
                prev[i]=-1;
        }

        long long A=X;
        prev[X]=0;

        long long ret=A;

        for(long long i=1; i<N;){
                A=(A*A)%M;

                long long prevpreva=prev[A];
                prev[A]=i;

                if(prevpreva != -1 && i>prevpreva && i-prevpreva <= M && N-i-3 > i-prevpreva) {
                        long long tmpsum=solve(i-prevpreva,A,M);
                        long long repeat = (N-i-2) / (i-prevpreva);
                        ret += tmpsum*repeat;
                        i+=(i-prevpreva)*repeat+1;
                        ret += A;
                } else{
                        ret += A;
                        ++i;
                }
        }

        return ret;
}

int main(){
        long long N,X,M;
        cin>>N>>X>>M;
        cout<<solve(N,X,M)<<endl;
}

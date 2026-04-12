#include <iostream>
#include <array>
#include <vector>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <set>

using namespace std;

typedef long long LL;
typedef vector<LL> VEC;
typedef vector<VEC> VVEC;
typedef  pair<LL,LL> P;


const LL INF=1<<30;
const LL MOD=1000000007;




int main(){

        int N;
        string S;
        int K;
        cin>>N>>S>>K;
        K--;
        for(int i=0;i<N;++i){
                if(S[i]!=S[K]){
                        S[i]='*';
                }
        }
        cout<<S<<endl;
}
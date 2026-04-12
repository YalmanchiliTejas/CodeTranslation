#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <utility>
#include <set>
#include <stack>
#include <climits>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>

namespace mp = boost::multiprecision;
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
#define MEMSET(v, h) memset((v), h, sizeof(v))
typedef long long ll;
const char sp = ' ';

using namespace mp;
using namespace std;

int main(void){
    ll K;
    cpp_int N;
    ll dl=0, di[101];
    cin>>N;
    cin>>K;
    rep(i, 100){
        if(N==(cpp_int)0) break;
        di[i]=(ll)(N%10);//cout<<di[i]<<endl;
        N/=10;
        dl++;
    }
    ll binded[3], nonbi[3];
    MEMSET(binded, 0);
    MEMSET(nonbi, 0);
    binded[2]=1;
    nonbi[2]=di[dl-1]-1;
    nonbi[3]=1;
    rep(i, dl-1){
        ll non[3];
        MEMSET(non, 0);
        int index=dl-i-2;
        if(di[index]!=0){
            //cout<<i<<sp<<di[index]<<endl;
            non[2]=binded[2];
            non[1]=binded[2]*(di[index]-1)+binded[1];
            non[0]=binded[1]*(di[index]-1)+binded[0];
            binded[0]=binded[1];
            binded[1]=binded[2];
            binded[2]=0;
        }
        nonbi[0]=nonbi[1]*9+nonbi[0]+non[0];
        nonbi[1]=nonbi[2]*9+nonbi[1]+non[1];
        nonbi[2]=nonbi[3]*9+nonbi[2]+non[2];
        /*cout<<binded[0]<<sp<<nonbi[0]<<endl;
        cout<<binded[1]<<sp<<nonbi[1]<<endl;
        cout<<binded[2]<<sp<<nonbi[2]<<endl;
        cout<<endl;*/
    }
    cout<<nonbi[3-K]+binded[3-K]<<endl;
    return 0;
}

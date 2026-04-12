#include<cctype>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cassert>
#include<algorithm>
#include<numeric>
#include<vector>
using std::vector;
#include<string>
using std::string;
#include<set>
using std::set;
#include<map>
using std::map;
#include<unordered_map>
#include<queue>
#include<tuple>
using std::get;
using std::pair;
using std::tuple;
#include<iostream>
#include<sstream>
#include<iomanip>
using lnt = long long int;
using unt = unsigned long long int;
using ust = unsigned;
using dou = double;
using P = std::pair<int,int>;
#define FZ(i,n)       for(int i=0;i<(n);++i)
#define FB(i,n)       for(int i=(n)-1;i>=0;--i)
#define FV(i,st,ed)   for(int i=st;i<(ed);++i)
#define FC(i,n)       for(int i=n;i;--i)
#define FZU(i,n)      for(ust i=0;i!=(n);++i)
#define FVU(i,st,ed)  for(ust i=st;i<(ed);++i)
#define FCU(i,n)      for(ust i=n;i;--i)
#define ALL(x)        std::begin(x),std::end(x)
#define DTRL(x,y)     do{auto&x_(x),&y_(y);if(x_!=y_)return x_<y_;}while(0)

#define RI(x) scanf("%d",&(x))
#define RII(x,y) scanf("%d %d",&(x),&(y))
#define RS(x) scanf("%s",x)
#define RI64(x) scanf("%lld",&(x))
#define RII64(x,y) scanf("%lld%lld",&(x),&(y))

#define FIR first
#define SEC second
#define pritnf printf
constexpr ust N = 100514u;

int main(){
    int n;
    std::cin >> n;
    int mx = -1;
    int ans = 0;
    for(int i=0;i<n;++i){
        int x;
        std::cin >> x;
        if(mx <= x){
            ++ans;
            mx = x;
        }
    }
    std::cout << ans << '\n';
}

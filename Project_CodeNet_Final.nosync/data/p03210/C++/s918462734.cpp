#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
struct fast_ios { fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;

#define ALL(x) (x).begin(), (x).end()
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)

const string YES = "YES";
const string NO = "NO";

void solve(long long X){
    if(X == 3 || X==5 || X==7){
        cout << YES << "\n";

    }else{
        cout << NO << "\n";
    }
}

int main(){

    long long X;
    scanf("%lld",&X);
    solve(X);
    return 0;
}


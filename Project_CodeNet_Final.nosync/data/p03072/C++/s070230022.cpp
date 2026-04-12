#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
#include <map>
#include<queue>
#include <sstream>
#include <set>
typedef  long long ll;
const int dx[8]={1,0,-1,0,1,-1,-1,1};
const int dy[8]={0,1,0,-1,1,1,-1,-1};
const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = { 0, 1, 0,-1};
const int INF = 1e9;
#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)
#define SORT(a) sort(a.begin(),a.end())
#define REVERSE(a) reverse(a.begin(),a.end())
int guki (int a){
    if(a%2==0) return 0;
    else return 1;
}
int gcd(int a, int b){
    if(a%b==0){
        return b;
    }else{
        return (gcd(b,a%b));
    }
}
int lcm(int a, int b){
    int x = gcd(a,b);
    return (a*b/x);
}
using namespace std;
int main(){
    int N,ans=1;
    cin >> N;
    vector<int> vec(N);

    REP(i,N){
        cin >> vec[i];
    }
    int s = vec[0];
    for(int i=1;i<N;i++){
        if(s <= vec[i]){
            s = vec[i];
            ans++;
        }
    }

    cout << ans <<endl;
}
#include<bits/stdc++.h>
/*
#include<iostream>
#include<vector>
#include<string>
#include<array>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<numeric>
#include<iomanip>
#include<utility>
#include<cstdlib>
#include<typeinfo>
#include<stack>
#include<cassert>
#include<functional>
*/
#define int long long int
#define double long double
using namespace std;
#define INT_DMAX 1000000007
#define INF 1000000000000000007
const int MAX_N = 1 << 17;
#define rep(i,n) for(int (i)=0, i##_len = (n);(i)<i##_len;(i)++)
#define reps(i,x) for(int (i)=1;(i)<=(int)(x);(i)++)
#define rrep(i,x) for(int (i)=((int)(x)-1);(i)>=0;(i)--)
#define rreps(i,x) for(int (i)=((int)(x));(i)>0;(i)--)
#define FOR(i,a,b) for (int (i) = (a); (i) < (b); (i)++)
#define pb push_back
#define mp make_pair
#define bit(n) ((int)(1)<<(n))
#define all(x) (x).begin(),(x).end()
#define debug(x) std::cout << #x << ": " << (x) << std::endl 

using namespace std;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};
typedef pair<int,int> p;
typedef pair<double,double> dop;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}
struct aaa{
    aaa(){
        cin.tie(0); ios::sync_with_stdio(0); cout<<fixed<<setprecision(20);
    };
}aaaaaaa;


signed main()
{
int n,x;
std::cin >> n >> x;
std::vector<int> count(1,1);
std::vector<int> pate(1,1);
for(int i = 1; i <= n; i++){
    count.pb(2 * count[i - 1] + 3);
    pate.pb(2 * pate[i - 1] + 1);
}

int it = n;
int sum = 0;
int now = 0;
int b = n;
int flag = 0;
while((count[it] - 1)/2 + 1 != x - now){
    if(it < 0){
        flag = 1;
        break;
    }
    if((count[it] - 1)/2 == x - now){
       sum += (pate[it] - 1)/2;
       flag = 1;
       break;
    }
    if((count[it] - 1) / 2 + now < x){
        sum += (pate[it]) / 2 + 1;
        now += (count[it])/2 + 1;
        it--;
    } else {
        it--;
        now++;
        if(x <= now || it < 0){
            flag = 1;
            break;
        }
    }
}
if(flag || (count[it] - 1)/2 + 1 + now < x){
    std::cout << sum << std::endl;
}else {
sum += (pate[it] - 1)/2 + 1;
std::cout << sum << std::endl;
}



return 0;
}
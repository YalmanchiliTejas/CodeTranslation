/*~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
*$* WRITER:kakitamasziru/OxOmisosiru *$*
~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=*/
#ifdef LOCAL_JUDGE
#define _GLIBCXX_DEBUG
#endif
#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <iomanip>
#include <limits>//setprecision
//#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
//#include <unordered_set> //unordered_set
#include <stack> // stack
#include <deque> // deque
#include <math.h>//pow,,,
#include <cmath>//abs,,,
#include <bitset> // bitset
#define endl "\n";
using namespace std;

const long long INF = 100100100100100100;
const int MOD = 1000000007;
const int inf = 1001001001;
typedef pair<int,int> P;

//Solve N^M. This, mod_pow use Iterative Square Method.
long long mod_pow(long long N, long long M) {
    if (M == 0) return 1;
    long long res = mod_pow((N * N) % MOD, M / 2);
    //最下位ビット(*N)が1の時は単独でNをかける
    if (M & 1) res = (res * N) % MOD;

    return res %= MOD;
}

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}
long long lcm(long long a, long long b) {
    return a / gcd(a, b) * b ;
}

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;cin >> N;
    vector<long long> retu(N);
    for(int i = 0;i<N;i++) cin >> retu.at(i);
    sort(retu.begin(),retu.end());
    deque<long long> DQ;
    for(int i = 0;i<N;i++){
        DQ.push_back(retu.at(i));
    }

    if(N % 2 == 1){
        //ans1は中央に最小値を持ってくる,ans2は中央に最大値を持ってくる
        deque<long long> ans1,ans2;
        deque<long long> centerMini = DQ;
        //ans2
        ans1.push_back(centerMini.front());
        centerMini.pop_front();
        for(int i = 0;i<N/2;i++){
            if(i % 2 == 0){
                ans1.push_front(centerMini.back());
                centerMini.pop_back();
                ans1.push_back(centerMini.back());
                centerMini.pop_back();
            }
            else{
                ans1.push_front(centerMini.front());
                centerMini.pop_front();
                ans1.push_back(centerMini.front());
                centerMini.pop_front();
            }
        }
        deque<long long> centerMaxi = DQ;
        //ans2
        ans2.push_back(centerMaxi.back());
        centerMaxi.pop_back();
        for(int i = 0;i<N/2;i++){
            if(i % 2 == 0){
                ans2.push_front(centerMaxi.front());
                centerMaxi.pop_front();
                ans2.push_back(centerMaxi.front());
                centerMaxi.pop_front();
            }
            else{
                ans2.push_front(centerMaxi.back());
                centerMaxi.pop_back();
                ans2.push_back(centerMaxi.back());
                centerMaxi.pop_back();
            }
        }
        long long Ans1 = 0,Ans2 = 0;
        long long A = 0,B = 0;
        //答えの計算
        for(int i = 0;i<N-1;i++){
            if(i == 0){
                A = ans1.front();ans1.pop_front();
                B = ans1.front();ans1.pop_front();
            }
            else{
                B = ans1.front();ans1.pop_front();
            }
            Ans1 += abs(A-B);
            A = B;
        }
        for(int i = 0;i<N-1;i++){
            if(i == 0){
                A = ans2.front();ans2.pop_front();
                B = ans2.front();ans2.pop_front();
            }
            else{
                B = ans2.front();ans2.pop_front();
            }
            Ans2 += abs(A-B);
            A = B;
        }
        cout << max(Ans1,Ans2) << endl;
        return 0;
    }
    if(N % 2 == 0){
        //N % 2 == 1とほぼ同様にやる
        deque<long long> ans1,ans2;
        deque<long long> centerMini = DQ;
        //ans2
        ans1.push_back(centerMini.front());
        centerMini.pop_front();
        for(int i = 0;i<(N-1)/2;i++){
            if(i % 2 == 0){
                ans1.push_front(centerMini.back());
                centerMini.pop_back();
                ans1.push_back(centerMini.back());
                centerMini.pop_back();
            }
            else{
                ans1.push_front(centerMini.front());
                centerMini.pop_front();
                ans1.push_back(centerMini.front());
                centerMini.pop_front();
            }
        }
        ans1.push_back(centerMini.front());
        deque<long long> centerMaxi = DQ;
        //ans2
        ans2.push_back(centerMaxi.back());
        centerMaxi.pop_back();
        for(int i = 0;i<(N-1)/2;i++){
            if(i % 2 == 0){
                ans2.push_front(centerMaxi.front());
                centerMaxi.pop_front();
                ans2.push_back(centerMaxi.front());
                centerMaxi.pop_front();
            }
            else{
                ans2.push_front(centerMaxi.back());
                centerMaxi.pop_back();
                ans2.push_back(centerMaxi.back());
                centerMaxi.pop_back();
            }
        }
        ans2.push_front(centerMaxi.front());
        long long Ans1 = 0,Ans2 = 0;
        long long A = 0,B = 0;
        //答えの計算
        for(int i = 0;i<N-1;i++){
            if(i == 0){
                A = ans1.front();ans1.pop_front();
                B = ans1.front();ans1.pop_front();
            }
            else{
                B = ans1.front();ans1.pop_front();
            }
            Ans1 += abs(A-B);
            A = B;
        }
        for(int i = 0;i<N-1;i++){
            if(i == 0){
                A = ans2.front();ans2.pop_front();
                B = ans2.front();ans2.pop_front();
            }
            else{
                B = ans2.front();ans2.pop_front();
            }
            Ans2 += abs(A-B);
            A = B;
        }
        cout << max(Ans1,Ans2) << endl;
        return 0;
    }
    
}

#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <iterator>
#include <algorithm>
#include <cfenv>
#include <random>
#include <numeric>
#include <cmath>
#include <iosfwd>
#include <iostream>
#include <ios>
#include <streambuf>
#include <istream>
#include <ostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include<string>
#include <bitset>

#define SIZE 200001
#define MOD 1000000007
typedef long long ll;
using namespace std;

int main(){
    ll N,A[SIZE];
    ll A_SUM[SIZE];
    ll ans=0;
    cin >> N ;
    for(int i = 1 ; i <= N ; i++){
        cin >> A[i];
    }
    for(int i = N-1 ; i >= 0 ; i--){
        if(i == N-1){
            A_SUM[N-1] = A[N];
        }else{
            A_SUM[i] = (A_SUM[i+1] + A[i+1]) % MOD;
        }
    }
    for(int i = 1 ; i <= N-1 ; i++){
        ans += (A[i]*A_SUM[i]) % MOD;
    }
    ans %= MOD;
    cout << ans << endl;
    return 0;
}
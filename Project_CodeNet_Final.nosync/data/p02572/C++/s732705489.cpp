//include
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath> 
#include <iomanip>
#include <math.h>
#include <utility>
//using
using namespace std;
/*using vi = vector <int>;
using vs = vector <string>;
using vc = vector <char>;*/
//define
#define int long long
#define rep(i,n) for(int i=0; i<n; i++)
#define print(n) cout<<n<<endl;


signed main(){
   int N;
    cin >> N;
    vector<int> A(N);
    int mod = 1000000007;
    int a = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        a += A[i];
        a %= mod;
    }
 
    int b = 0;
 
    for (int i = 0; i < N; i++)
    {
     
        a -= A[i];
        if (a < 0) a += mod;
 
        b += A[i] * a;
        b %= mod;
    }
 
    cout << b << endl;
}

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

long long  mod = 1000000007;

int main(){
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    rep(i,n){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b.begin(),b.end());
    rep(i,n){
        if(a[i]>=b[n/2]){
            cout << b[n/2-1] << endl;
        }else{
            cout << b[n/2] << endl;
        }
    }

    return 0;
}
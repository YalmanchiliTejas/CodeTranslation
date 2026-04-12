#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define RFOR(i, a, b) for (int i = (a); i >= (b); i--)
#define LFOR(i, a, b) for (long long int i = (a); i <= (b); i++)
#define LRFOR(i, a, b) for (long long int i = (a); i >= (b); i--)
#define MOD 1000000007
#define INF 1000000000           // 2000000000
#define LINF 1000000000000000000 // 9000000000000000000
#define DINF 1000000000000000.0
#define PI 3.14159265358979

//.size()はunsigned int　0-1をするとオーバーフローする

using namespace std;
typedef long long int ll;
typedef pair<long long int, long long int> P;

int dy[5] = {-1, 0, 1, 0, 0};
int dx[5] = {0, -1, 0, 1, 0};

int main(void) {
    int n,m;

    cin>>n>>m;

    if(n==m){
        cout<<"Yes"<<endl;
    }else {
        cout<<"No"<<endl;
    }
}

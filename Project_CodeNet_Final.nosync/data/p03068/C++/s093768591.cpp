#include <utility>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <cmath>
#define REP(i,n) for(int i=0;i<n;i++)
typedef unsigned long ul;
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};


int main() {
	cin.tie(0);
   	ios::sync_with_stdio(false);
    int K, N;
    string S;
    cin >> N >> S >> K;
    string ans(N, 'a');
    for(int i = 0; i < N; i++){
        if(S[i] == S[K-1]){
            ans.at(i) = S[K-1];
        }else{
            ans.at(i) = '*';
        }
    }
    cout << ans << endl;
    return 0;
}
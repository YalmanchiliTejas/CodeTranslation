#include <utility>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
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
    int X;
    cin >>X;
    string ans;
    if(X == 3 || X==5 || X==7){
        ans = "YES";
    }else{
        ans = "NO";
    }
    cout << ans << endl;
    return 0;
}
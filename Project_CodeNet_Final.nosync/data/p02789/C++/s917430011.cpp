#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <map>
#include <queue>
#include <vector>
#define mem(i,a) memset(i,a,sizeof(i))
#define PI acos(-1.0)
#define DMAX 100000+5
#define MOD 20190823
#define eps 1e-8
#define mp make_pair
#define INF 1000000000+9
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
inline void read(ll &f){
	f=0;
    ll x=1;
    char ch=getchar();
    while(ch<48 || ch>57) {
        if(ch=='-') {
            x=-1;
        }
        ch=getchar();
    }
    while(ch<=57 && ch>=48) {
        f=f*10+ch-'0';
        ch=getchar();
    }
    f*=x;
} 
int n,m;
int main(){
    cin>>n>>m;
    if(n==m){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
    return 0;
}
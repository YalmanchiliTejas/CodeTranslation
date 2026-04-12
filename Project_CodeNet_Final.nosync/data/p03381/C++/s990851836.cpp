#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <ctime>
#include <algorithm>
#include <map>
#define MAXN 200005
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ba 823
#define mo 974711
//#define ivorysi
using namespace std;
typedef long long int64;
typedef double db;
int N;
int id[MAXN],X[MAXN],B[MAXN];
bool cmp(int a,int b) {
	return X[a] < X[b];
}
int main() {
#ifdef ivorysi
    freopen("f1.in","r",stdin);
#endif
    scanf("%d",&N);
    for(int i = 1 ; i <= N ; ++i) {
    	scanf("%d",&X[i]);
    	id[i] = i;
    }
    sort(id + 1,id + N + 1,cmp);
    int T = N / 2;
    for(int i = 1 ; i <= T ; ++i) {
    	B[id[i]] = X[id[T + 1]];
    }
    for(int i = T + 1 ; i <= N ; ++i) {
    	B[id[i]] = X[id[T]];
    }
    for(int i = 1 ; i <= N ; ++i) {
    	printf("%d\n",B[i]);
    }
    return 0;
}
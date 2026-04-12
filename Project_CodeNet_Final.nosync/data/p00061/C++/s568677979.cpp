#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> P;

int main(){
    int m,n;
    priority_queue<P> ranq;
    while( scanf("%d,%d", &m, &n) , m ){
        ranq.push( P(n, m) );
    }
    int rank[101], s = 1000000, i = 0;
    while( !ranq.empty() ){
        P a = ranq.top();
        ranq.pop();
        if( a.first < s ){
            i++;
            s = a.first;
        }
        rank[a.second] = i;
    }
    while( scanf("%d", &n) != EOF ) printf("%d\n", rank[n]); 
    return 0;
}
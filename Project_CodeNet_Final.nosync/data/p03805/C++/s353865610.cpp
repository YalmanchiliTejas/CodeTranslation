#include<iostream>
#include<vector>
#include<string>
#include<array>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<numeric>
#include<iomanip>
#include<utility>
#include<cstdlib>
#include<typeinfo>
#include<stack>
#include<cassert>
#include<functional>
#define int long long int
#define double long double
using namespace std;
#define INT_MAX 1000000005
#define INF 1000000005
const int MAX_N = 1 << 17;
#define REP(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;


typedef struct{
    int check[8];
    int sum = 0;
    int now;

} checker;
typedef struct {
    std::vector<int> nextnode;
} nenode;




signed main()
{
int n,m;
std::cin >> n >> m;
std::vector<nenode> nodelist(n);
for(int i = 0; i < m; i++){
    int a,b;
    std::cin >> a >> b;
    nodelist[a - 1].nextnode.push_back(b - 1);
    nodelist[b - 1].nextnode.push_back(a - 1);
}

std::queue<checker> path;
int sum = 0;
checker start;
for(int i = 0; i < 8; i++){
    start.check[i] = 0;
}
start.check[0] = 1;
start.sum++;
start.now = 0;
path.push(start);
while(!path.empty()){
    checker now = path.front();
    path.pop();
    if(now.sum == n){
        sum++;
        continue;
    }
    for(int i = 0; i < nodelist[now.now].nextnode.size(); i++){
        if(now.check[nodelist[now.now].nextnode[i]] == 1){
           continue;
        } else {
            checker next;
            for(int k = 0; k < 8; k++){
                next.check[k] = now.check[k];
            }
            next.check[nodelist[now.now].nextnode[i]] = 1;
            next.sum = now.sum + 1;
            next.now = nodelist[now.now].nextnode[i]; 
            path.push(next);
        }
    }
} 
std::cout << sum << std::endl;

return 0;
}
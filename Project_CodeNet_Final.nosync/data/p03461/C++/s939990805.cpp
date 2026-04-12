#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
const int inf = 99999;
int A, B;
int d[11][11];
vector<piii> E;

int main(){
    scanf("%d%d",&A,&B);
    for(int i=1;i<=A;i++){
        for(int j=1;j<=B;j++){
            scanf("%d", &d[i][j]);
        }
    }
    for(int a=0;a<100;a++){
        for(int b=0;b<100;b++){
            int c = -1;
            for(int x=1;x<=A;x++){
                for(int y=1;y<=B;y++){
                    c = max(d[x][y] - a*x - b*y, c);
                }
            }
            if (c >= 0 && c <= 100)E.emplace_back(pii(a,b),c);
        }
    }
    for(int i=1;i<=A;i++){
        for(int j=1;j<=B;j++){
            int mn = inf;
            for(auto e : E){
                mn = min(mn, e.first.first * i + e.first.second * j + e.second);
            }
            if(mn != d[i][j]){
                puts("Impossible");
                return 0;
            }
        }
    }
    puts("Possible");
    printf("%d %d\n", 200, (int)E.size() + 198);
    for(int i=1;i<100;i++){
        printf("%d %d X\n", i, i+1);
    }
    for(int j=101;j<200;j++){
        printf("%d %d Y\n", j+1, j);
    }
    for(auto e : E){
        int a = e.first.first;
        int b = e.first.second;
        int c = e.second;
        printf("%d %d %d\n", 1+a, 101+b, c);
    }
    printf("%d %d\n", 1, 101);
}

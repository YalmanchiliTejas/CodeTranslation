#include <cstdio>
#include <algorithm>
#include <map>
#include <cstdlib>
using namespace std;

struct T{
    char team[22];
    int score;
} ;

bool operator==(const T& left, const T& right)
{
    return left.score == right.score;
}
bool operator<(const T& left, const T& right)
{
    return left.score > right.score;
}
bool operator>(const T& left, const T& right)
{
    return left.score < right.score;
}


int main(void)
{
    int w, l, d = -1;
    
    while (1){
        int n;
        scanf("%d", &n);
        if (!n) break;
        if (d != -1) printf("\n");
        
        struct T set[n];
        
        for (int i = 0; i < n; i++){
            scanf("%s %d %d %d", set[i].team, &w, &l, &d);
            set[i].score = (w * 3) + (d * 1);
        }
        
        stable_sort(set, set + n);
        
        for (int i = 0; i < n; i++){
            printf("%s,%d\n", set[i].team, set[i].score);
        }
    }
    
    return (0);
}
#include <cstdio>
#include <set>

using namespace std;

void debug(multiset<long> hoge){
    for(auto i=hoge.begin(); i != hoge.end(); i++){
        printf("%ld, ", *i);
    }
    printf("\n");
}

int main(){
    multiset<long> colors;
    int n;
    scanf("%d", &n);
    int a;
    for(int i=0; i < n; i++){
        scanf("%d", &a);
        decltype(colors)::iterator it = colors.upper_bound(-a);
        if(it == colors.end()){
            colors.insert(-a);
            // printf("new color\n");
        }else{
            colors.erase(it);
            colors.insert(-a);
        }
        // debug(colors);
    }
    printf("%d\n", colors.size());
    return 0;
}
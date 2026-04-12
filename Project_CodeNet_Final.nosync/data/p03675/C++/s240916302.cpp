#include <cstdio>
#include <queue>

using namespace std;

int n;
deque<int> b;

int main(){
    scanf("%d", &n);
    for(int i=0;i<n;++i){
        int tmp;
        scanf("%d", &tmp);
        if(i%2){
            b.push_front(tmp);
        }else{
            b.push_back(tmp);
        }
    }
    if(n%2){
        while(!b.empty()){
            printf("%d ", b.back());
            b.pop_back();
        }
    }else{
        while(!b.empty()){
            printf("%d ", b.front());
            b.pop_front();
        }
    }
}

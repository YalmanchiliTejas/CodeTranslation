#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int main(){
    stack<char> yama[100];
    char order[10],block;
    int num,to,yama_n;
    
    scanf("%d",&yama_n);
    
    while(1){
        scanf("%s",order);
        
        switch(order[2]){
                case 's':
                    scanf("%d %c",&num,&block);
                    yama[num-1].push(block);
                    break;
                case 'p':
                    scanf("%d",&num);
                    cout << yama[num-1].top() << endl;
                    yama[num-1].pop();
                    break;
                case 'v':
                    scanf("%d %d",&num,&to);
                    yama[to-1].push(yama[num-1].top());
                    yama[num-1].pop();
                    break;
                case 'i':
                    return 0;
        }
    }
    
    return 0;
}
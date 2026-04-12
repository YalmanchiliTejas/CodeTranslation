#include <iostream>
using namespace std;

int n, stones[100001], sum;
int main(){
    while(cin >> n && n){
        for(int i = 1; i <= n; i++){
            cin >> stones[i];
            if(i % 2 == 0 && stones[i] != stones[i - 1]){
                for(int j = i - 1; j > 0; j--){
                    if(stones[j] != stones[i]){
                        stones[j] = stones[i];
                    } else{
                        break;
                    }
                }
            }
        }

        sum = 0;
        for(int i = 1; i <= n; i++){
            if(!stones[i]){
                sum++;
            }
        }

        cout << sum << endl;
    }

    return 0;
}
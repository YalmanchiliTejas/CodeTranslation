#include <bits/stdc++.h>
using namespace std;

int main() {
    int score[100];
    int i,j;
    int n;
    int tmp;
    int sum;
    int scorel;
    
    while(1){
        sum = 0;
        cin >> n;
        if(n == 0){
            break;
        }
        
        for(i = 0;i < n;i++){
            cin >> score[i];
        }
        
        for(i = 0;i < n - 1;i++){
            for(j = i + 1;j < n;j++){
                if(score[i] > score[j]){
                    tmp = score[i];
                    score[i] = score[j];
                    score[j] = tmp;
                }
            }
        }
        
        for(i = 1;i < n - 1;i++){
            sum = sum + score[i];
        }
        
        scorel = sum / (n - 2);
        
        cout << scorel << endl;
        
    }
}
